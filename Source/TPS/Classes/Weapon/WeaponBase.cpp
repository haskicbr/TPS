#include "WeaponBase.h"

#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"

AWeaponBase::AWeaponBase()
{
  PrimaryActorTick.bCanEverTick = true;
  SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(
    "Mesh"
  );
  SetRootComponent(
    SkeletalMeshComponent
  );

  IsEquipped = false;
}

void AWeaponBase::BeginPlay()
{
  Super::BeginPlay();
}

void AWeaponBase::Tick(float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );
}

void AWeaponBase::Fire(const FVector To)
{
  const FVector From = SkeletalMeshComponent->GetSocketLocation(ProjectileSocketName);

  const FVector Direction = To - From;
  const FRotator Rotation = Direction.Rotation();

  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    __FUNCTION__
  );

  FActorSpawnParameters SpawnParameters;


  APawn* PawnOwner = Cast<APawn>(
  GetOwner()
  );

  if (PawnOwner)
  {
    SpawnParameters.Instigator = PawnOwner;
  }


  //SpawnParameters.Owner = InstigatorPawn;
  //SpawnParameters.Instigator = InstigatorPawn;

  GetWorld()->SpawnActor<AProjectile>(
    Projectile,
    From,
    Rotation,
    SpawnParameters
  );
}

// TODO: Update weapon base class for use static mesh for drop item
void AWeaponBase::DropFromActor()
{
  /*auto Rules = FDetachmentTransformRules(
    EDetachmentRule::KeepWorld,
    EDetachmentRule::KeepWorld,
    EDetachmentRule::KeepWorld,
    true
  );
  this->DetachFromActor(Rules);
  this->SkeletalMeshComponent->SetSimulatePhysics(true);*/
}
