// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Serializer.generated.h"

/**
 * 
 */
UCLASS()
class CS380_FINALCPP_API USerializer : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Serialize")
	static bool SaveArrayText(FString saveDir, FString fileName, TArray<FString> text);

};
