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
    VE_FR30Probe  UMETA(DisplayName = "FR30 Probe"),
    VE_FR45Probe  UMETA(DisplayName = "FR45 Probe"),
    VE_FR60Probe  UMETA(DisplayName = "FR60 Probe"),
    VE_FR75Probe  UMETA(DisplayName = "FR75 Probe"),
    VE_RProbe  UMETA(DisplayName = "R Probe"),
    VE_FL15Probe  UMETA(DisplayName = "FL15 Probe"),
    VE_FL30Probe  UMETA(DisplayName = "FL30 Probe"),
    VE_FL45Probe  UMETA(DisplayName = "FL45 Probe"),
    VE_FL60Probe  UMETA(DisplayName = "FL60 Probe"),
    VE_FL75Probe  UMETA(DisplayName = "FL75 Probe"),
    VE_LProbe  UMETA(DisplayName = "L Probe"),
    VE_BR15Probe  UMETA(DisplayName = "BR15 Probe"),
    VE_BR30Probe  UMETA(DisplayName = "BR30 Probe"),
    VE_BR45Probe  UMETA(DisplayName = "BR45 Probe"),
    VE_BR60Probe  UMETA(DisplayName = "BR60 Probe"),
    VE_BR75Probe  UMETA(DisplayName = "BR75 Probe"),
    VE_BProbe  UMETA(DisplayName = "B Probe"),
    VE_BL15Probe  UMETA(DisplayName = "BL15 Probe"),
    VE_BL30Probe  UMETA(DisplayName = "BL30 Probe"),
    VE_BL45Probe  UMETA(DisplayName = "BL45 Probe"),
    VE_BL60Probe  UMETA(DisplayName = "BL60 Probe"),
    VE_BL75Probe  UMETA(DisplayName = "BL75 Probe"),
    VE_UProbe UMETA(DisplayName= "Up Probe"),
    Count UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(ESensoryType, ESensoryType::Count);
