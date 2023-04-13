// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ESensoryType.h"
#include "EActionType.h"
#include "FMPNode.generated.h"

/**
 *
 */
USTRUCT()
struct CS380_FINALCPP_API FMPNode {
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> weights;

	UPROPERTY()
	ESensoryType sensory_type;

	UPROPERTY()
	EActionType action;

	UPROPERTY()
	float activation;
};
