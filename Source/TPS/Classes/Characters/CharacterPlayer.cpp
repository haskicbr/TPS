#include "Characters/CharacterPlayer.h"
#include "Camera/CameraComponent.h"

ACharacterPlayer::ACharacterPlayer()
{
  PrimaryActorTick.bCanEverTick = true;
  CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
  CameraComponent->SetupAttachment(GetRootComponent());
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
