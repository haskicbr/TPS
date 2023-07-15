#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Components/Inventory/InventoryItem.h"
#include "Components/Inventory/InventoryItemParams.h"
#include "SaveGameData.generated.h"


class ACharacterBase;
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
  ACharacterBase* Character;

  UPROPERTY(
    VisibleAnywhere
  )
  TMap<FString, UInventoryItem*> Inventory;

  UPROPERTY(VisibleAnywhere)
  TArray<FInventoryItemParams> Objects;

  UPROPERTY(EditAnywhere)
  TArray<TSubclassOf<AActor>> TestsObjects;
};
