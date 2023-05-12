#include "CharacterBase.h"

ACharacterBase::ACharacterBase()
{
  PrimaryActorTick.bCanEverTick = true;
}

void ACharacterBase::BeginPlay()
{
  Super::BeginPlay();
}

void ACharacterBase::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}

void ACharacterBase::MoveForward(float ForwardAxis)
{
}

void ACharacterBase::MoveRight(float RightAxis)
{
}
