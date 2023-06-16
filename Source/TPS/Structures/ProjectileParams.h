#pragma once

#include "CoreMinimal.h"
#include "ProjectileParams.generated.h"

USTRUCT(BlueprintType)
struct FProjectileParams
{
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BulletParams")
  float Damage = 5;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BulletParams")
  float Spray = 0.1;

  UPROPERTY()
  UObject* SafeObjectPointer;
};
