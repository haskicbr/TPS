// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"


UCLASS()
class TPS_API UInventoryItem : public UObject
{
  GENERATED_BODY()

public:
  UPROPERTY(
    VisibleAnywhere
  )
  int32 Count = 1;

  UPROPERTY(
    VisibleAnywhere
  )
  int32 CountMax = 1;

  UPROPERTY(
    VisibleAnywhere
  )
  bool IsUsable = false;
  UPROPERTY(
    VisibleAnywhere
  )
  bool IsCountable = false;
  UPROPERTY(
    VisibleAnywhere
  )
  FString Uid = FGuid::NewGuid().ToString();
  UPROPERTY(
    VisibleAnywhere
  )
  FString TimeSpan = "";
  UPROPERTY(
    VisibleAnywhere
  )
  AActor* ObjectInWorld = nullptr;
};
