// Fill out your copyright notice in the Description page of Project Settings.


#include "MultilayerPerceptronBase.h"

#include "EActionType.h"
#include "ESensoryType.h"

// Sets default values for this component's properties
UMultilayerPerceptronBase::UMultilayerPerceptronBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMultilayerPerceptronBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMultilayerPerceptronBase::SetStructure(int layer_depth, int layer_count) {
	layers.Empty();
	for (int layer_index = 0; layer_index < layer_count; ++layer_index) {
		auto layer = TArray<Node>();
		for (int node_index = 0; node_index < layer_depth; ++node_index) {
			Node node;
			node.weights = TArray<float>();
			node.activation = 0.0f;
			layer.Add(node);
		}
		layers.Add(layer);
	}
}

void UMultilayerPerceptronBase::Seed(TArray<float> genome) {
	//clear i/o
	inputs.Empty();
	outputs.Empty();

	//set up input layer
	for (auto sensory_type : TEnumRange<ESensoryType>()) {
		Node node;
		node.weights = TArray<float>();
		node.sensory_type = sensory_type;
		node.action = EActionType::Count;
		node.activation = 0.0f;
		inputs.Add(node);
	}

	//set up output layer
	auto& final_layer = inputs;
	if (layers.Num()) final_layer = layers.Top();
	for (auto action_type : TEnumRange<EActionType>()) {
		Node node;
		node.weights = TArray<float>();
		for (int i = genome.Num() - final_layer.Num(); i >= 0 && i < genome.Num(); ++i) {
			node.weights.Add(genome[i]);
		}
		node.sensory_type = ESensoryType::Count;
		node.action = action_type;
		node.activation = 0.0f;
		outputs.Add(node);
	}

	//fill intermediary layers
	int genome_offset = 0;
	auto& prior_layer = inputs;
	for (auto& layer : layers) {
		for (auto& node : layer) {
			node.weights.Empty();
			for (int i = 0; i < prior_layer.Num() && genome_offset < genome.Num(); ++i) {
				node.weights.Add(genome[genome_offset++]);
			}
			node.activation = 0.0f;
		}
	}
}

void UMultilayerPerceptronBase::Perceive(ESensoryType sensory_type, float normalized) {
	//Update inputs from the SensoryType
	for(auto& node : inputs){
		if(node.sensory_type == sensory_type) node.activation = normalized;
	}

}

void UMultilayerPerceptronBase::ActOnPerceptions() {

	auto apply_weights = [](TArray<Node>& prior, Node& node) {
		int weight_end = std::min(prior.Num(), node.weights.Num()); //gracefully handle mismatches in size
		float sum = 0.0f;
		for (int weight_index = 0; weight_index < weight_end; ++weight_index) {
			auto prior_node = prior[weight_index];
			auto weight = node.weights[weight_index];
			//normalize into -1 to 1
			weight = (weight * 2.0f) - 1.0f;
			//accumulate
			sum += prior_node.activation * weight;
		}
		node.activation = sum / weight_end;
	};
	//Run forward propagation
	if (layers.Num()) {
		TArray<Node>& prior = inputs;
		for (auto& layer : layers) {
			for (auto& node : layer) {
				apply_weights(prior, node);
			}
			prior = layer;
		}
		for (auto& node : outputs) {
			apply_weights(prior, node);
		}
	}
	//Distribute outputs as events to controllers
	if (OnActionUpdate.IsBound()) {
		for (auto& node : outputs) {
			OnActionUpdate.Broadcast(id, node.action, ActivationThreshold(node.activation));
		}
	}
}

float UMultilayerPerceptronBase::NormalizeUnbounded(float raw, float significant_range) {
	float ranged = raw / significant_range;
	return 1.0f - (1.0f / (1.0f + ranged*ranged));
}

float UMultilayerPerceptronBase::ActivationThreshold(float normalized) {
	//leaky RelU
	return std::max(0.01f * normalized, normalized);
}


// Called every frame
void UMultilayerPerceptronBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

