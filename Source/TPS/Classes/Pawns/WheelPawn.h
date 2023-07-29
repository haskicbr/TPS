// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "Characters/CharacterBase.h"
#include "WheelPawn.generated.h"

UCLASS(
  Blueprintable
)
class TPS_API AWheelPawn : public AWheeledVehiclePawn
{
  GENERATED_BODY()

public:
  UPROPERTY(
    BlueprintReadWrite
  )
  ACharacterBase* CharacterInteractable;
};
