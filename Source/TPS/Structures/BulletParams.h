#pragma once

#include "CoreMinimal.h"
#include "BulletParams.generated.h"

USTRUCT(BlueprintType)
struct FBulletParams
{
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Direction")
  FVector StartPoint;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Direction")
  FVector Direction;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Direction")
  double Damage;

  UPROPERTY()
  UObject* SafeObjectPointer;
};
