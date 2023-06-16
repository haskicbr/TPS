#include "Characters/CharacterPlayer.h"
#include "Camera/CameraComponent.h"


ACharacterPlayer::ACharacterPlayer()
{

  PrimaryActorTick.bCanEverTick = true;
  CameraComponent = CreateDefaultSubobject<UCameraComponent>(
    TEXT(
      "CameraComponent"
    )
  );

  SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(
    "SpringArmComponent"
  );

  SpringArmComponent->SetupAttachment(
    GetRootComponent()
  );
  SpringArmComponent->TargetArmLength = 600.f;


  CameraComponent->SetupAttachment(
    SpringArmComponent
  );

  SpringArmComponent->bUsePawnControlRotation = true;


  static ConstructorHelpers::FObjectFinder<UAnimMontage> MontageAsset(
    TEXT(
      "Montage'/Game/Main/Blueprints/AM_Test'"
    )
  );

  Montage = MontageAsset.Object;
}


void ACharacterPlayer::MoveForward(float ForwardAxis)
{
  AddMovementInput(
    GetActorForwardVector(),
    ForwardAxis
  );
}

void ACharacterPlayer::MoveRight(float RightAxis)
{
  AddMovementInput(
    GetActorRightVector(),
    RightAxis
  );
}

void ACharacterPlayer::Turn(float Axis)
{
  AddControllerYawInput(
    Axis
  );
}

void ACharacterPlayer::LookUp(float Axis)
{
  AddControllerPitchInput(
    Axis
  );
}
