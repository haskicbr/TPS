#include "CharacterBaseAnimInstance.h"
#include "KismetAnimationLibrary.h"

void UCharacterBaseAnimInstance::NativeBeginPlay()
{
  Super::NativeBeginPlay();
  InitializeCharacter();
}


void UCharacterBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
  Super::NativeUpdateAnimation(
    DeltaSeconds
  );

  if (!CurrentCharacter.IsValid())
  {
    InitializeCharacter();
    return;
  }


  const UCharacterMovementComponent* CharacterMovementComponent = CurrentCharacter->GetCharacterMovement();
  Speed = CharacterMovementComponent->Velocity.Size();
  bIsFalling = CharacterMovementComponent->IsFalling();
  bIsDead = CurrentCharacter->bIsDeath;


  const FVector Velocity = CurrentCharacter->GetVelocity();
  const FRotator Rotator = CurrentCharacter->GetActorRotation();

  VerticalAim = CurrentCharacter->GetBaseAimRotation().Pitch;

  DirectionAngle = UKismetAnimationLibrary::CalculateDirection(
    Velocity,
    Rotator
  );
}

void UCharacterBaseAnimInstance::InitializeCharacter()
{

  CurrentCharacter = StaticCast<ACharacterBase*>(
    TryGetPawnOwner()
  );
}
