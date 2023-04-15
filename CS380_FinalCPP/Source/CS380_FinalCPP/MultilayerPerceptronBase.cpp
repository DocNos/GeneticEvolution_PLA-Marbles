// Fill out your copyright notice in the Description page of Project Settings.


#include "MultilayerPerceptronBase.h"

#include "DrawDebugHelpers.h"
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

void UMultilayerPerceptronBase::DrawLayers(FVector world_origin) {
	int offset = 0;
	TArray<FColor> colors;
	for(int r = 0; r <= 100; r += 15){
		for(int g = 0; g <= 100; g += 15){
			for(int b = 0; b <= 100; b += 15){
				if((r + g + b) > 50 && (std::abs(r - b) + std::abs(r-g) + std::abs(b-g)) > 20) {
					colors.Add(FColor(r, g, b, 100));
				}
			}
		}
	}
	
	int prior_target = 0;
	for(int i = 0; i < colors.Num(); ++i){
		prior_target = (75 * prior_target + 74) % 65537;
		int shuffle_target = prior_target % colors.Num();
		colors.Swap(i, shuffle_target);
	}
	int gap = 5;

	int node_offset = 0;
	//draw float weight on the right side of the ball
	auto draw_weight = [this,world_origin, gap, &offset, &node_offset, &colors](float progress) {
		FColor active_color = colors[node_offset % colors.Num()];
		FVector vertical = FVector(0, 0, offset + 100 + gap/2.0);
		DrawDebugLine(GetWorld(), world_origin+vertical, FVector(0, -100, 0) + vertical + world_origin, FColor::Black, false, 0.0f, 0, gap);
		DrawDebugLine(GetWorld(), world_origin+vertical, FVector(0, -progress*100, 0) + vertical + world_origin, active_color, false, 0.0f, 0, gap);
	};
	//draw node activation on the left side of the ball
	auto draw_activation = [this,world_origin, gap, &offset, &colors](float progress, float size) {
		FColor active_color = colors[offset % colors.Num()];
		FVector vertical = FVector(0, 0, offset + 100 + size/2.0);
		DrawDebugLine(GetWorld(), world_origin+vertical, FVector(0, 100, 0) + vertical + world_origin, FColor(progress, progress*10, progress*100, 100), false, 0.0f, 0, size);
	};

	//draw a gap between nodes
	auto draw_space = [this, world_origin, gap, &offset]() {
		FVector vertical = FVector(0, 100, offset + 100 + gap);
		DrawDebugLine(GetWorld(), world_origin + vertical, FVector(0, -200, 0) + vertical + world_origin, FColor(20,20,20,90), false, 0.0f, 0, gap*2);
		offset += gap*2;
	};


	auto draw_node = [gap, &offset, &node_offset, &draw_weight, & draw_activation, & draw_space](FMPNode& node){
		for(auto& weight : node.weights){
			draw_weight(weight);
			offset += gap;
		}
		offset -= gap * node.weights.Num();
		draw_activation(node.activation, gap*node.weights.Num());
		offset += gap * node.weights.Num();
		draw_space();
		++node_offset;
	};


	for (auto& node : outputs) {
		draw_node(node);
	}	
	for (auto& node : layers) {
		draw_node(node);
	}
	for (auto& node : inputs) {
		draw_node(node);
	}
}

void UMultilayerPerceptronBase::SetStructure(int num_layer_nodes, int num_layers) {
	layer_count = num_layers;
	layer_height = num_layer_nodes;

	layers.Empty();
	for (int layer_index = 0; layer_index < layer_count; ++layer_index) {
		for (int node_index = 0; node_index < layer_height; ++node_index) {
			FMPNode node;
			node.weights = TArray<float>();
			node.activation = 0.0f;
			layers.Add(node);
		}
	}
}

void UMultilayerPerceptronBase::Seed(TArray<float> genome) {
	//clear i/o
	inputs.Empty();
	outputs.Empty();

	//set up input layer
	int node_count = 0;
	for (auto sensory_type : TEnumRange<ESensoryType>()) {
		FMPNode node;
		node.weights = TArray<float>();
		node.sensory_type = sensory_type;
		node.action = EActionType::Count;
		node.activation = 0.0f;
		inputs.Add(node);
		//UE_LOG(LogTemp, Log, TEXT("Sensory Range for Node %d: %d"), ++node_count, (uint8_t)sensory_type);
		//UE_LOG(LogTemp, Log, TEXT("Actual Sensory Range for Node %d: %d"), node_count, node.sensory_type);
	}

	int genome_offset = 0;
	//set up output layer
	for (auto action_type : TEnumRange<EActionType>()) {
		FMPNode node;
		node.weights = TArray<float>();
		for (int i = 0; i < layer_height && genome_offset < genome.Num(); ++i) {
			node.weights.Add(genome[genome_offset++]);
		}
		node.sensory_type = ESensoryType::Count;
		node.action = action_type;
		node.activation = 0.0f;
		outputs.Add(node);
	}

	//set up input-adjacent layer
	for(int i = 0; i < layer_height && i < layers.Num(); ++i){ //for first layer
		auto& node = layers[i];
		node.weights.Empty();
		for(int j = 0; j < inputs.Num() && genome_offset < genome.Num(); ++j){ //for each input
			node.weights.Add(genome[genome_offset++]); //add weight
		}
	}

	//fill intermediary layers
	for(int i = layer_height; i < layers.Num(); ++i){
		auto& node = layers[i];
		node.weights.Empty();
		for (int j = 0; j < layer_height && genome_offset < genome.Num(); ++j) {
			node.weights.Add(genome[genome_offset++]);
		}
		node.activation = 0.0f;
	}
}

void UMultilayerPerceptronBase::Perceive(ESensoryType sensory_type, float normalized) {
	//Update inputs from the SensoryType
	int node_count = 0;
	for(auto& node : inputs){
		//UE_LOG(LogTemp, Log, TEXT("Node %d has sensory type %d, looking for %d"), ++node_count, (uint8_t) node.sensory_type, (uint8_t) sensory_type);

		if (node.sensory_type == sensory_type) {
			node.activation = normalized;
			return;
		}
	}
	//UE_LOG(LogTemp, Log, TEXT("Could not find sensory type in input nodes, size %d"), inputs.Num());
}

void UMultilayerPerceptronBase::ActOnPerceptions() {

	auto apply_weights = [](TArray<FMPNode>& nodes, int offset, FMPNode& node) {
		float sum = 0.0f; //FMath::RandRange(0, 1000);
		for (int weight_index = 0; weight_index < node.weights.Num(); ++weight_index) {
			if(nodes.Num() <= offset + weight_index) continue; //don't crash out on mismatches
			auto& prior_node = nodes[offset + weight_index];
			auto weight = node.weights[weight_index];
			//normalize into -1 to 1
			weight = (weight * 2.0f) - 1.0f; // 0:1 genome adjusted to be -1 : 1
			//accumulate
			sum += prior_node.activation * weight;
		}
		node.activation = sum / node.weights.Num();
	};
	//Run forward propagation
	if (layers.Num()) {
		//reach input layer
		for(int i = 0; i < layer_height && i < layers.Num(); ++i){
			apply_weights(inputs, 0, layers[i]);
		}

		//run on inner layers
		for(int layer = 1; layer < layer_count; ++layer){
			for(int node = 0; node < layer_height; ++node){
				apply_weights(layers, (layer-1)*layer_height, layers[(layer*layer_height)+node]);
			}
		}

		//reach output layer
		for (auto& node : outputs) {
			apply_weights(layers, (layer_count-1)*layer_height, node);
		}
	}else{
		for(int i = 0; i < outputs.Num(); ++i){
			apply_weights(inputs, 0, outputs[i]);
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

