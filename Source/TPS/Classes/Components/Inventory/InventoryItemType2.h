#pragma once

#include "CoreMinimal.h"
#include "InventoryItemType2.generated.h"

UENUM(BlueprintType)
enum EInventoryItemType2
{
  WeaponMelee2 UMETA(
    DisplayName = "WeaponMelee"
  ),
  WeaponRange2 UMETA(
    DisplayName = "WeaponRange"
  ),
  WeaponRangeAmmo2 UMETA(
    DisplayName = "WeaponRangeAmmo"
  ),
  Consumable2 UMETA(
    DisplayName = "Consumable"
  ),
};
