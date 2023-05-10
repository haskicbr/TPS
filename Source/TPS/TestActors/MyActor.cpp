#include "MyActor.h"
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector2D AMyActor::GetTestVector(double& AOut, double& BOut) const
{
	AOut = this->TestVector.X;
	BOut = this->TestVector.Y;

	return this->TestVector;
}

