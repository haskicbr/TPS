#include "WeaponBase.h"

#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

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

void AWeaponBase::Shoot()
{

  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    __FUNCTION__
  );


  APawn* InstigatorPawn = Cast<APawn>(
    GetOwner()
  );

  FActorSpawnParameters SpawnParameters;

  SpawnParameters.Owner = GetOwner();
  SpawnParameters.Instigator = InstigatorPawn;


  /*
  SkeletalMeshComponent->GetSocketLocation()
  */

  GetWorld()->SpawnActor<AProjectile>(
    Projectile,
    GetActorLocation() + GetActorForwardVector() * 4 + GetActorUpVector() * 2,
    FRotator(
      0,
      0,
      0
    ),
    SpawnParameters
  );
}
