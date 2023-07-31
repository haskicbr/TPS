// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Inventory/InventoryItemParams.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TPS_API AMyActor : public AActor
{
  GENERATED_BODY()

public:
  AMyActor();

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  AActor * TestActor;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UObject * TestObject;

  UPROPERTY()
  UDataTable* DT;

  UPROPERTY()
  FSoftObjectPath UnitDataTablePath = FSoftObjectPath(TEXT("/Game/Main/Test/NewDataTable"));

  UPROPERTY()
  FSoftObjectPath WorldInventoryTablePath = FSoftObjectPath(TEXT("/Game/Main/Data/DT_InventoryObjects"));

  UPROPERTY(EditAnywhere)
  FVector2D TestVector;

  UPROPERTY(EditAnywhere, Category="InventoryTest123123123")
  TArray<FInventoryItemParams> InventoryItems;


  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
  TArray<AActor*> TestActors;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
  TSubclassOf<AActor> TestSoftObject;

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;
  void Test();

  FTimerHandle TestTickHandle;

  UFUNCTION(BlueprintCallable)
  FVector2D GetTestVector(double& AOut, double& BOut) const;
};
