#include "InventoryComponent.h"



UInventoryComponent::UInventoryComponent()
{
  PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::BeginPlay()
{
  UInventoryItem* InventoryItem = NewObject<UInventoryItem>();
  InventoryItem->CountMax = 10;
  InventoryItem->Count = 5;

  Super::BeginPlay();
  Inventory.Add(
    FString(
      "test"
    ),
    InventoryItem
  );

  for (auto Result : Inventory)
  {
    GEngine->AddOnScreenDebugMessage(
      -1,
      4.5f,
      FColor::Purple,
      InventoryItem->GetName()
    );
  }
}

void UInventoryComponent::TickComponent(
  float DeltaTime,
  ELevelTick TickType,
  FActorComponentTickFunction* ThisTickFunction
)
{
  Super::TickComponent(
    DeltaTime,
    TickType,
    ThisTickFunction
  );
}
