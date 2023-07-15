#include "MyActor.h"

#include "Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"
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
  Weapon->SetChildActorClass(
    ATriggeredLight::StaticClass()
  );
}

void AMyActor::BeginPlay()
{
  //FDataTableRowHandle().DataTable->GetAllRows()

  Super::BeginPlay();

  for(int i =0; i< 100; i++)
  {
    auto item = FInventoryItemParams();

    item.Count = 0;

    item.RowName = FName(
      FString(
        "Testname"
      )
    );

    item.Type = EInventoryItemType::Consumable;

    InventoryItems.Add(
      item
    );

    // InventoryItems.Remove(item);
  }

  GetWorldTimerManager().SetTimer(TestTickHandle, this, &AMyActor::Test, 5.0f);

}

void AMyActor::Tick(float DeltaTime)
{
  Super::Tick(
    DeltaTime
  );
}

void AMyActor::Test()
{
  GEngine->AddOnScreenDebugMessage(
  -1,
  4.5f,
  FColor::Red,
  __FUNCTION__
  );

  GetWorldTimerManager().ClearTimer(this->TestTickHandle);
}





FVector2D AMyActor::GetTestVector(double& AOut, double& BOut) const
{
  AOut = this->TestVector.X;
  BOut = this->TestVector.Y;

  return this->TestVector;
}
