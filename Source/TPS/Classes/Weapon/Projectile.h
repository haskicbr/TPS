#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Sound/SoundCue.h"
#include "Projectile.generated.h"

UCLASS()
class TPS_API AProjectile : public AActor
{
  GENERATED_BODY()

public:
  AProjectile();

protected:
  virtual void BeginPlay() override;

  UFUNCTION()
  virtual void OnHit(
    UPrimitiveComponent* HitComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit
  );

  virtual void Destroyed() override;

private:

  UPROPERTY(EditAnywhere)
  float DamageValue = 5.0;

  UPROPERTY(
    EditAnywhere
  )
  UBoxComponent* CollisionBox;

  UPROPERTY(
    EditAnywhere
  )
  UProjectileMovementComponent* ProjectileMovementComponent;

  UPROPERTY(
    EditAnywhere
  )
  UParticleSystem* TraceParticle;
  UPROPERTY(
    EditAnywhere
  )
  UParticleSystem* ImpactParticle;

  UPROPERTY(
    EditAnywhere
  )
  UParticleSystemComponent* ParticleSystemTrace;

  UPROPERTY(
    EditAnywhere
  )
  UParticleSystemComponent* ParticleSystemImpact;

  UPROPERTY(
    EditAnywhere
  )
  USoundCue* ImpactSound;
};
