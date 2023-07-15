#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryEquippementSlot.generated.h"


UCLASS()
class TPS_API UInventoryEquipmentSlot : public UObject
{
  GENERATED_BODY()

public:
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  bool bIsFree = true;
};
