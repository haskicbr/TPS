#include "Projectile.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"


AProjectile::AProjectile()
{
  PrimaryActorTick.bCanEverTick = false;
  CollisionBox = CreateDefaultSubobject<UBoxComponent>(
    "CollisionBox"
  );
  ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
    "ProjectileMovementComponent"
  );

  SetRootComponent(
    CollisionBox
  );

  CollisionBox->SetCollisionObjectType(
    ECC_WorldDynamic
  );
  CollisionBox->SetCollisionEnabled(
    ECollisionEnabled::QueryAndPhysics
  );

  CollisionBox->SetCollisionResponseToAllChannels(
    ECR_Ignore
  );


  CollisionBox->SetCollisionResponseToChannel(
    ECC_Visibility,
    ECR_Block
  );
  CollisionBox->SetCollisionResponseToChannel(
    ECC_WorldStatic,
    ECR_Block
  );

  ProjectileMovementComponent->bRotationFollowsVelocity = true;

  /*AActor::SetLifeSpan(
    3.0
  );*/
}

void AProjectile::BeginPlay()
{
  Super::BeginPlay();


  if (TraceParticle)
  {
    UGameplayStatics::SpawnEmitterAttached(
      TraceParticle,
      CollisionBox,
      FName(),
      GetActorLocation(),
      GetActorRotation(),
      EAttachLocation::KeepWorldPosition
    );
  }


  CollisionBox->OnComponentHit.AddDynamic(
    this,
    &AProjectile::OnHit
  );
}

void AProjectile::OnHit(
  UPrimitiveComponent* HitComp,
  AActor* OtherActor,
  UPrimitiveComponent* OtherComp,
  FVector NormalImpulse,
  const FHitResult& Hit
)
{
  Destroyed();
}

void AProjectile::Destroyed()
{
  UGameplayStatics::SpawnEmitterAtLocation(
    GetWorld(),
    ImpactParticle,
    GetActorTransform()
  );

  UGameplayStatics::PlaySoundAtLocation(
    GetWorld(),
    ImpactSound,
    GetActorLocation()
  );

  Super::Destroyed();
}
