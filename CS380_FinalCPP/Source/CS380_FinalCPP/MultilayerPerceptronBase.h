// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MultilayerPerceptronBase.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(Blueprintable, BlueprintSpawnableComponent) )
class CS380_FINALCPP_API UMultilayerPerceptronBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMultilayerPerceptronBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Perceptron")
	void SetStructure(int layer_depth, int layer_count);

	UFUNCTION(BlueprintCallable, Category = "Perceptron")
	void Seed(TArray<float>& genome);

	UFUNCTION(BlueprintCallable, Category = "Perceptron")
	void Perceive(ESensoryType sensory_type, float normalized);

	UFUNCTION(BlueprintCallable, Category = "Perceptron")
	void ActOnPerceptions();

	UFUNCTION(BlueprintCallable, Category = "Math")
	static float NormalizeUnbounded(float raw, float significant_range);

	UFUNCTION(BlueprintCallable, Category = "Math")
	static float ActivationThreshold(float normalized);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
