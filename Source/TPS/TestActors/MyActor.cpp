#include "MyActor.h"

#include "Light/TriggeredLight.h"

AMyActor::AMyActor()
{
  PrimaryActorTick.bCanEverTick = true;

  auto* Weapon = CreateDefaultSubobject<UChildActorComponent>(
    TEXT(
      "Weapon"
    )
  );
  Weapon->SetupAttachment(
    GetRootComponent()
  );
  Weapon->SetChildActorClass(ATriggeredLight::StaticClass());
}

void AMyActor::BeginPlay()
{
  Super::BeginPlay();
}

void AMyActor::Tick(float DeltaTime)
{
  Super::Tick(
    DeltaTime
  );
}

FVector2D AMyActor::GetTestVector(double& AOut, double& BOut) const
{
  AOut = this->TestVector.X;
  BOut = this->TestVector.Y;

  return this->TestVector;
}
