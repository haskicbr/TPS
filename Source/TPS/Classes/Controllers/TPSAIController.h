// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Characters/CharacterBase.h"
#include "TPSAIController.generated.h"


/**
 *
 */
UCLASS()
class TPS_API ATPSAIController : public AAIController
{
	GENERATED_BODY()


public:
  UFUNCTION(BlueprintCallable)
  void TestMove(FVector Location);

  UFUNCTION(BlueprintCallable)
  virtual void Fire();

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  class ACharacterBase* ControlledCharacter;

protected:
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
};
