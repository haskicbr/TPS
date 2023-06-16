#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Components/Inventory/InventoryItem.h"
#include "SaveGameData.generated.h"

UCLASS()
class TPS_API USaveGameData : public USaveGame
{
  GENERATED_BODY()

public:
  UPROPERTY(
    VisibleAnywhere
  )
  FTransform CharacterTransform;



  UPROPERTY(
    VisibleAnywhere
  )
  AActor* Character;

  UPROPERTY(
    VisibleAnywhere
  )
  UInventoryItem* InventoryItem;
};
