#include "CharacterBase.h"

#include "Components/AttributesComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Inventory/InventoryComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacterBase::ACharacterBase()
{
  PrimaryActorTick.bCanEverTick = true;

  InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(
    TEXT(
      "InventoryComponent"
    )
  );

  AttributesComponent = CreateDefaultSubobject<UAttributesComponent>(
    TEXT(
      "AttributesComponent"
    )
  );

  AttributesComponent->OnDeath.AddDynamic(
    this,
    &ACharacterBase::Death
  );
}

void ACharacterBase::BeginPlay()
{
  Super::BeginPlay();
}

void ACharacterBase::Tick(const float DeltaTime)
{
  Super::Tick(
    DeltaTime
  );
}

void ACharacterBase::MoveForward(float ForwardAxis)
{
}

void ACharacterBase::MoveRight(float RightAxis)
{
}


float ACharacterBase::TakeDamage(
  float DamageAmount,
  FDamageEvent const& DamageEvent,
  AController* EventInstigator,
  AActor* DamageCauser
)
{
  AttributesComponent->ChangeHealth(
    -DamageAmount
  );

  return Super::TakeDamage(
    DamageAmount,
    DamageEvent,
    EventInstigator,
    DamageCauser
  );
}

void ACharacterBase::Death()
{
  IsDeath = true;
  this->GetMovementComponent()->Deactivate();
  AController* CharacterController = Cast<AController>(
    GetController()
  );

  if (CharacterController)
  {
    CharacterController->UnPossess();
  }
  GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
