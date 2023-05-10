#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/Actor.h"
#include "TPS/Interfaces/CanActivate.h"
#include "TriggeredLight.generated.h"

UCLASS()
class TPS_API ATriggeredLight : public AActor, public ICanActivate
{
  GENERATED_BODY()

public:
  ATriggeredLight();

  UFUNCTION()
  void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                    int32 OtherBodyIndex);
  UFUNCTION()
  void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
                      int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

protected:
  virtual void BeginPlay() override;

public:
  UPROPERTY(EditAnywhere)
  USceneComponent* DefaultRoot;

  UPROPERTY(EditAnywhere)
  UStaticMeshComponent* StaticMesh;

  UPROPERTY(EditAnywhere)
  UPointLightComponent* PointLight;

  virtual void Activate() override;
  virtual void Deactivate() override;
};
