// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EActionType : uint8 {
    VE_ForwardImpulse  UMETA(DisplayName = "Forward Impulse"),
    VE_LeftImpulse  UMETA(DisplayName = "Left Impulse"),
    VE_RightImpulse  UMETA(DisplayName = "Right Impulse"),
    VE_BackImpulse  UMETA(DisplayName = "Back Impulse"),
    VE_JumpImpulse  UMETA(DisplayName = "Jump Impulse"),
    Count UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EActionType, EActionType::Count);