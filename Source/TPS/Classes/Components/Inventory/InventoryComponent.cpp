#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
  PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
  Super::BeginPlay();

  UInventoryItem* InventoryItem = NewObject<UInventoryItem>();

  InventoryItem->CountMax = 10;
  InventoryItem->Count = 5;

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
