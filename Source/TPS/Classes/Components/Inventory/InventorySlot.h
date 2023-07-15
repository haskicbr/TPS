// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventorySlot.generated.h"


UCLASS()
class TPS_API UInventorySlot : public UObject
{
  GENERATED_BODY()

public:
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  FVector2D Position;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  bool bIsFree = true;
};
