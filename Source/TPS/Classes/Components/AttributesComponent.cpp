#include "AttributesComponent.h"

UAttributesComponent::UAttributesComponent()
{
  PrimaryComponentTick.bCanEverTick = false;
}

void UAttributesComponent::BeginPlay()
{
  Super::BeginPlay();


  ChangeHealth(
    0
  );
}

void UAttributesComponent::ChangeHealth(float HealthParam)
{
  if (Health > 0)
  {
    Health += HealthParam;
  }

  if (Health <= 0)
  {
    OnDeath.Broadcast();
  }

  OnChangeHealth.Broadcast(
    Health,
    HealthMax
  );
}
