// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TPSAIController.h"

#include "Characters/CharacterBase.h"
#include "Weapon/WeaponBase.h"
#include "GameFramework/CharacterMovementComponent.h"


void ATPSAIController::TestMove(FVector Location)
{
  MoveToLocation(
    Location
  );
}


void ATPSAIController::Fire()
{
  if (ControlledCharacter->Weapon)
  {
    const USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

    if (ControlledCharacter)
    {
      SkeletalMeshComponent = Cast<USkeletalMeshComponent>(
        ControlledCharacter->GetComponentByClass(
          USkeletalMeshComponent::StaticClass()
        )
      );
    }

    if (SkeletalMeshComponent)
    {
      ControlledCharacter->Weapon->Fire(
        ControlledCharacter->GetActorLocation() + ControlledCharacter->GetActorForwardVector() * 10000
      );
    }
  }
}

void ATPSAIController::BeginPlay()
{
  Super::BeginPlay();
  ControlledCharacter = Cast<ACharacterBase>(
    GetCharacter()
  );
}

void ATPSAIController::Tick(float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );
}
