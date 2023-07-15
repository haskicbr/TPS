#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemType.h"
#include "InventoryItem.generated.h"


class UInventoryComponent;

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
    VisibleAnywhere
  )
  FVector2D SlotPositionInventory;

  UPROPERTY(
    VisibleAnywhere
  )
  FString SlotAttachedName;

  UPROPERTY(
    VisibleAnywhere
  )
  UInventoryComponent* InventoryComponent;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadWrite
  )
  int32 Count = 1;

  UPROPERTY(
    EditInstanceOnly,
    BlueprintReadOnly
  )
  int32 CountMax = 1;

  UPROPERTY(
  EditInstanceOnly,
  BlueprintReadOnly
  )
  bool bIsUsable = false;
  UPROPERTY(
    EditInstanceOnly,
    BlueprintReadOnly
  )
  bool bIsCountable = false;

  UPROPERTY(VisibleAnywhere)
  bool bIsAttachable = false;

  UPROPERTY(VisibleAnywhere)
  FString AttachSlotId;


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
