#include "CharacterBase.h"

#include "Components/AttributesComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Inventory/InventoryComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon/WeaponBase.h"

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

  GetCharacterMovement()->JumpZVelocity = 700.f;
  GetCharacterMovement()->AirControl = 0.35f;
  GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
  GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
  GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
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

void ACharacterBase::SprintStart()
{
  if (!CanSprint())
  {
    return;
  }

  GetCharacterMovement()->MaxWalkSpeed = MaxSprintSpeed;
}

void ACharacterBase::SprintStop()
{
  GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

bool ACharacterBase::CanSprint()
{
  if(CanJump())
  {
    return true;
  }

  return false;
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
  bIsDeath = true;
  this->GetMovementComponent()->Deactivate();

  AController* CharacterController = Cast<AController>(
    GetController()
  );

  if (CharacterController)
  {
    CharacterController->UnPossess();
  }

  if (Weapon)
  {
    Weapon->DropFromActor();
  }

  //GetCapsuleComponent()->RemoveFromRoot();
  GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

  GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
  GetMesh()->SetCollisionProfileName("Ragdoll");
  GetMesh()->SetSimulatePhysics(true);
}
