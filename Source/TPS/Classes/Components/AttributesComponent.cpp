#include "AttributesComponent.h"

UAttributesComponent::UAttributesComponent()
{
  PrimaryComponentTick.bCanEverTick = false;
}

void UAttributesComponent::BeginPlay()
{
  Super::BeginPlay();
}

void UAttributesComponent::ChangeHealth(float HealthParam)
{
  if (Health > 0)
  {
    Health += HealthParam;
  }

  OnChangeHealth.Broadcast(Health, HealthMax);
}
