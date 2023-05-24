#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UENUM()
enum EInventoryItemType
{
  WeaponMelee UMETA(
    DisplayName = "WeaponMelee"
  ),
  WeaponRange UMETA(
    DisplayName = "WeaponRange"
  ),
  WeaponRangeAmmo UMETA(
    DisplayName = "Weapon"
  ),
  Consumable UMETA(
    DisplayName = "Consumable"
  ),
};

USTRUCT()
struct FInventoryItemParams
{
  GENERATED_BODY()
  EInventoryItemType Type = EInventoryItemType::Consumable;
  int32 Count = 0;
  int32 CountMax = 0;
};


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

  virtual void TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction
  ) override;
};
