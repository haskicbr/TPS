// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class TPS_API ACharacterBase : public ACharacter
{
  GENERATED_BODY()

public:
  ACharacterBase();

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;

  virtual void MoveForward(float ForwardAxis);
  virtual void MoveRight(float RightAxis);
};
