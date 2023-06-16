#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UCLASS(
  ClassGroup=(Custom),
  meta=(BlueprintSpawnableComponent)
)
class TPS_API UInventoryComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  UInventoryComponent();

protected:
  virtual void BeginPlay() override;

public:
  UPROPERTY(
    EditAnywhere
  )
  TMap<FString, UInventoryItem*> Inventory;

  UFUNCTION()
  void AddItem(UInventoryItem* Item)
  {
    Inventory.Add(
      FGuid::NewGuid().ToString(),
      Item
    );
  }

};
