#include "CharacterBaseAnimInstance.h"

void UCharacterBaseAnimInstance::NativeBeginPlay()
{
  Super::NativeBeginPlay();
  checkf(
    TryGetPawnOwner()->IsA<ACharacterBase>(),
    TEXT("UCharacterBaseAnimInstance::NativeBeginPlay() this class use only ACharacterBase cnass and instances")
  )
  CurrentCharacter = StaticCast<ACharacterBase*>(
    TryGetPawnOwner()
  );
}

void UCharacterBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
  Super::NativeUpdateAnimation(
    DeltaSeconds
  );

  if (!CurrentCharacter.IsValid())
  {
    return;
  }

  const UCharacterMovementComponent* CharacterMovementComponent = CurrentCharacter->GetCharacterMovement();
  Speed = CharacterMovementComponent->Velocity.Size();
  bIsFalling = CharacterMovementComponent->IsFalling();
  bIsDead = CurrentCharacter->bIsDeath;


  const auto Velocity =  CurrentCharacter->GetVelocity();
  const auto Rotator = CurrentCharacter->GetActorRotation();


  DirectionAngle = CalculateDirection(
    Velocity,
    Rotator
  );
}
