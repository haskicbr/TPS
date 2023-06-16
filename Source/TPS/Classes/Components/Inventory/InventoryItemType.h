#pragma once

#include "CoreMinimal.h"
#include "InventoryItemType.generated.h"

UENUM(BlueprintType)
enum EInventoryItemType
{
  WeaponMelee UMETA(
    DisplayName = "WeaponMelee"
  ),
  WeaponRange UMETA(
    DisplayName = "WeaponRange"
  ),
  WeaponRangeAmmo UMETA(
    DisplayName = "WeaponRangeAmmo"
  ),
  Consumable UMETA(
    DisplayName = "Consumable"
  ),
};
