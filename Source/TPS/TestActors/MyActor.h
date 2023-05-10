// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TPS_API AMyActor : public AActor
{
  GENERATED_BODY()

public:
  AMyActor();

  UPROPERTY(EditAnywhere)
  FVector2D TestVector;

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;

  UFUNCTION(BlueprintCallable)
  FVector2D GetTestVector(double& AOut, double& BOut) const;
};
