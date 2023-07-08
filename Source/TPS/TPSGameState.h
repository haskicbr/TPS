// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TPSGameState.generated.h"


UCLASS()
class TPS_API ATPSGameState : public AGameStateBase
{
	GENERATED_BODY()
public:

  UPROPERTY(BlueprintReadOnly, EditAnywhere)
  FSoftObjectPath InventoryWorldObjectsTablePath = FSoftObjectPath(TEXT("/Game/Main/Data/DT_InventoryWorldObjects"));

  TArray<FInventoryWorldObjectParams*> InventoryWorldObjectParams;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int Counter = 10;

  virtual void BeginPlay() override;

private:
  void FillInventoryData();
};
