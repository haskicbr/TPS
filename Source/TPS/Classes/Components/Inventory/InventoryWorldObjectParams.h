#pragma once
#include "Engine/DataTable.h"
#include "InventoryWorldObjectParams.generated.h"

USTRUCT(
  BlueprintType
)
struct TPS_API FInventoryWorldObjectParams : public FTableRowBase
{
  GENERATED_BODY()

  UPROPERTY(
    EditAnywhere
  )
  TSubclassOf<AActor> PickupItem;

  UPROPERTY(
    EditAnywhere
  )
  TSubclassOf<AActor> ActorInWorld;
};
