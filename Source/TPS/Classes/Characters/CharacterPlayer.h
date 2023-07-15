#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Controllers/TPSController.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterPlayer.generated.h"

UCLASS()
class TPS_API ACharacterPlayer : public ACharacterBase
{
  GENERATED_BODY()

public:

  UPROPERTY(VisibleAnywhere)
  ATPSController * PlayerController;

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
  ACharacterPlayer();
  virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
  virtual void MoveForward(float ForwardAxis) override;
  virtual void MoveRight(float RightAxis) override;
  void Turn(float RightAxis);
  void LookUp(float RightAxis);
  virtual void PossessedBy(AController* NewController) override;
  virtual void Fire();
  virtual void PrintFire();
  virtual void BeginPlay() override
  {
    Super::BeginPlay();
  }
  virtual void Tick(float DeltaSeconds) override;
  void UpdateAudioListener() const;
};
