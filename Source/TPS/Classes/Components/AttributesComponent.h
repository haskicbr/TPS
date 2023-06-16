// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
  FChangeHealthDelegate,
  float,
  CurrentHealth,
  float,
  MaxHealth
);

UCLASS(
  ClassGroup=(Custom),
  meta=(BlueprintSpawnableComponent)
)

class TPS_API UAttributesComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  UAttributesComponent();

protected:
  virtual void BeginPlay() override;

public:
  UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Attributes")
  float Health = 100.0;
  UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Attributes")
  float HealthMax = 100.0;

  UPROPERTY(
    BlueprintAssignable
  )
  FChangeHealthDelegate OnChangeHealth;


  UFUNCTION(BlueprintCallable)
  void ChangeHealth(float NewHealth);
};
