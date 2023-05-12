// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "CharacterPlayer.generated.h"


UCLASS()
class TPS_API ACharacterPlayer : public ACharacterBase
{
  GENERATED_BODY()
public:
  ACharacterPlayer();
  void MoveForward(float ForwardAxis) override;
  void MoveRight(float RightAxis);
  void Turn(float RightAxis);
  void LookUp(float RightAxis);

protected:
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Components)
  class UCameraComponent* CameraComponent;
};
