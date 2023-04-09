// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
UENUM(BlueprintType)
enum class ESensoryType : uint8 {
    VE_Rightness  UMETA(DisplayName = "Rightness"),
    VE_Leftness  UMETA(DisplayName = "Leftness"),
    VE_Inertia  UMETA(DisplayName = "Inertia"),
    VE_FProbe  UMETA(DisplayName = "F Probe"),
    VE_FR15Probe  UMETA(DisplayName = "FR15 Probe"),
    VE_FL15Probe  UMETA(DisplayName = "FL15 Probe"),
    Count UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(ESensoryType, ESensoryType::Count);
