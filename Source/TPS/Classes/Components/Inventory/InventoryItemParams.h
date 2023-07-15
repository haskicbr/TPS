#pragma once
#include "InventoryItemType.h"
#include "Engine/DataTable.h"
#include "InventoryItemParams.generated.h"

USTRUCT(
  BlueprintType
)
struct TPS_API FInventoryItemParams : public FTableRowBase
{
  GENERATED_BODY()

  UPROPERTY(
    VisibleAnywhere
  )
  FName RowName = "EmptyRowName";

  UPROPERTY(
    VisibleAnywhere
  )
  int32 Count = 0;

  UPROPERTY(
    VisibleAnywhere
  )
  bool bIsEquipped;

  UPROPERTY(
    VisibleAnywhere
  )
  FString SlotContainerId = "EmptySlotId";

  UPROPERTY(
    VisibleAnywhere
  )
  FVector2D InventorySlotPosition = FVector2D();

  UPROPERTY(
    VisibleAnywhere
  )
  TEnumAsByte<EInventoryItemType> Type = EInventoryItemType::Undefined;

  UPROPERTY(
    VisibleAnywhere
  )
  TSubclassOf<AActor> InitialActor;
};
