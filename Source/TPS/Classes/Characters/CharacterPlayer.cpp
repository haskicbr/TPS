#include "Characters/CharacterPlayer.h"
#include "Camera/CameraComponent.h"


ACharacterPlayer::ACharacterPlayer()
{
  PrimaryActorTick.bCanEverTick = true;
  CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

  SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
  SpringArmComponent->SetupAttachment(GetRootComponent());
  SpringArmComponent->TargetArmLength = 600.f;
  SpringArmComponent->bUsePawnControlRotation = false;

  CameraComponent->SetupAttachment(SpringArmComponent);
}


void ACharacterPlayer::MoveForward(float ForwardAxis)
{
  AddMovementInput(GetActorForwardVector(), ForwardAxis);
}

void ACharacterPlayer::MoveRight(float RightAxis)
{
  AddMovementInput(GetActorRightVector(), RightAxis);
}

void ACharacterPlayer::Turn(float Axis)
{
  AddControllerYawInput(Axis);
}

void ACharacterPlayer::LookUp(float Axis)
{
  AddControllerPitchInput(Axis);
}
