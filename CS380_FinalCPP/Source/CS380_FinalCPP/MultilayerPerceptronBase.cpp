// Fill out your copyright notice in the Description page of Project Settings.


#include "MultilayerPerceptronBase.h"

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

}

void UMultilayerPerceptronBase::Seed(TArray<float>& genome) {

}

void UMultilayerPerceptronBase::Perceive(ESensoryType sensory_type, float normalized) {

}

void UMultilayerPerceptronBase::ActOnPerceptions() {

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

