#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemType.h"
#include "InventoryItem.generated.h"

UCLASS(
  Blueprintable,
  BlueprintType,
  EditInlineNew
)
class TPS_API UInventoryItem : public UObject
{
  GENERATED_BODY()

public:
  UInventoryItem();

  UPROPERTY(
    EditAnywhere
  )
  TEnumAsByte<EInventoryItemType> InventoryType = EInventoryItemType::Consumable;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadWrite
  )
  int32 Count = 1;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadOnly
  )
  int32 CountMax = 1;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadOnly
  )
  bool IsUsable = false;
  UPROPERTY(
    EditAnywhere
  )
  bool IsCountable = false;

  UPROPERTY(
    EditAnywhere
  )
  FString TimeSpan = "";

  UPROPERTY(
    EditAnywhere,
    BlueprintReadOnly
  )

  UStaticMesh* StaticMesh;

  UPROPERTY(
    EditDefaultsOnly,
    BlueprintReadOnly
  )
  TSubclassOf<AActor> ActorInWorld;

  UPROPERTY(
    EditDefaultsOnly,
    BlueprintReadOnly
  )
  TSubclassOf<AActor> PickupActor;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadOnly
  )
  UTexture2D* Icon;
};
