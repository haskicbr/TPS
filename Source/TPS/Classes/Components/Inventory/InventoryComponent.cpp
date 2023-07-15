#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
  PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
  Super::BeginPlay();

  Owner = GetOwner();

  UInventoryItem* InventoryItem = NewObject<UInventoryItem>();

  InventoryItem->CountMax = 10;
  InventoryItem->Count = 5;
  InventoryItem->SlotPositionInventory = FVector2D(2, 3);
  Inventory.Add(
    FString(
      "test"
    ),
    InventoryItem
  );


  FInventoryItemParams params = FInventoryItemParams();

  if(InventoryItem->ActorInWorld)
  {
    params.InitialActor = InventoryItem->ActorInWorld->GetClass();
  }




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

void UInventoryComponent::AddItem(UInventoryItem* Item)
{
  Inventory.Add(
    FString::FromInt(Item->GetUniqueID()),
    Item
  );
}

void UInventoryComponent::DropItem(UInventoryItem* Item)
{
  Owner = GetOwner();

  FVector DropLocation = Owner->GetActorLocation();
  DropLocation = DropLocation += Owner->GetActorForwardVector() * 100;

  GetWorld()->SpawnActor<APickupItem>(
    Item->PickupActor,
    DropLocation,
    Owner->GetActorRotation()
  );

  Item->ConditionalBeginDestroy();
}


void UInventoryComponent::InitializeInventory()
{

}
