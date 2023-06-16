#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterPlayer.generated.h"

UCLASS()
class TPS_API ACharacterPlayer : public ACharacterBase
{
  GENERATED_BODY()

public:
  ACharacterPlayer();

  virtual void MoveForward(float ForwardAxis) override;
  virtual void MoveRight(float RightAxis) override;
  void Turn(float RightAxis);
  void LookUp(float RightAxis);

  virtual void BeginPlay() override
  {
    Super::BeginPlay();
  }

  UPROPERTY(
    VisibleAnywhere,
    BlueprintReadWrite,
    Category=Components
  )
  class UCameraComponent* CameraComponent;


  UPROPERTY(
    VisibleAnywhere,
    BlueprintReadWrite,
    Category=Components
  )
  class USpringArmComponent* SpringArmComponent;

  UPROPERTY(
    VisibleAnywhere,
    BlueprintReadWrite,
    Category=Components
  )
  UAnimMontage* Montage;
};
