// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class TPS_API AWeaponBase : public AActor
{
  GENERATED_BODY()

public:
  bool IsEquipped;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<AProjectile> Projectile;

  AWeaponBase();

protected:
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;

public:
  UPROPERTY(VisibleAnywhere)
  USkeletalMeshComponent* SkeletalMeshComponent;

  UPROPERTY(VisibleAnywhere)
  FName ProjectileSocketName = FName("ProjectileSocket");

  UFUNCTION(BlueprintCallable, Category=Weapon)
  void Shoot();
};
