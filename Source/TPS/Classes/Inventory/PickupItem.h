#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"

UCLASS()
class TPS_API APickupItem : public AActor
{
  GENERATED_BODY()

public:
  APickupItem();

  UPROPERTY(
    EditAnywhere
  )
  USceneComponent* DefaultRoot;

  UPROPERTY(
    EditAnywhere
  )
  UInventoryItem* InventoryItem;


  UPROPERTY(
    EditAnywhere
  )
  UStaticMeshComponent* StaticMesh;

protected:
  virtual void BeginPlay() override;

  UFUNCTION()
  void OnOverlapEnd(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex
  );

  UFUNCTION()
  void OnOverlapBegin(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& Hit
  );
};
