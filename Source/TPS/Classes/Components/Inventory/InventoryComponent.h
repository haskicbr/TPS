#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "InventoryItemParams.h"
#include "Components/ActorComponent.h"
#include "PickupItem.h"
#include "Engine/DataTable.h"
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


  UPROPERTY(VisibleAnywhere)
  FInventoryItemParams Params123 ;

  UPROPERTY(
    VisibleAnywhere
  )
  AActor* Owner;

  UPROPERTY(
    VisibleAnywhere,
    BlueprintReadOnly
  )
  TArray<FVector2D> InventorySlots;

  UPROPERTY(
    VisibleAnywhere
  )
  TMap<FString, UInventoryItem*> Inventory;

  UFUNCTION()
  void AddItem(UInventoryItem* Item);

  UFUNCTION()
  void DropItem(UInventoryItem* Item);

  UFUNCTION()
  virtual void InitializeInventory();

protected:
  virtual void BeginPlay() override;
};
