// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"


UENUM(BlueprintType)
enum EMovementState
{
  CantMove UMETA(DisplayName="Can't move"),
  CanMove UMETA(DisplayName="Can move"),
};

UCLASS()
class TPS_API ACharacterBase : public ACharacter
{
  GENERATED_BODY()

public:
  ACharacterBase();


  UPROPERTY(VisibleAnywhere)
  float MaxWalkSpeed = 350.f;

  UPROPERTY(VisibleAnywhere)
  float MaxSprintSpeed = 700.f;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  bool bIsDeath = false;

  UPROPERTY(
    EditInstanceOnly,
    BlueprintReadWrite
  )
  class UInventoryComponent* InventoryComponent;


  UPROPERTY(
    EditInstanceOnly,
    BlueprintReadWrite
  )
  class UAttributesComponent* AttributesComponent;


  UPROPERTY(
    VisibleAnywhere
  )
  FName WeaponMainSocketName = FName(
    "WeaponMainSocket"
  );

  UPROPERTY(
    VisibleAnywhere
  )
  FName WeaponSecondarySocketName = FName(
    "WeaponSecondarySocket"
  );

  UPROPERTY(
    VisibleAnywhere
  )
  class AWeaponBase* Weapon;

  UPROPERTY(
    VisibleAnywhere
  )
  AActor* ActorInteractable;

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;
  virtual void MoveForward(float ForwardAxis);
  virtual void MoveRight(float RightAxis);
  virtual void SprintStart();
  virtual void SprintStop();
  virtual bool CanSprint();


  UFUNCTION()
  virtual float TakeDamage(
    float DamageAmount,
    FDamageEvent const& DamageEvent,
    AController* EventInstigator,
    AActor* DamageCauser
  ) override;

  UFUNCTION()
  virtual void Death();
};


