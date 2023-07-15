#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/TPSHud.h"
#include "TPSController.generated.h"

UCLASS()
class TPS_API ATPSController : public APlayerController
{
  GENERATED_BODY()

public:
  ATPSController();

  UPROPERTY(
    VisibleAnywhere,
    BlueprintReadOnly
  )
  ACharacterPlayer* ControlledCharacter;

  UPROPERTY()
  FVector TargetPointFromCenterScreen = FVector();
  FHitResult * TargetHitFromCenterScreen;

  UPROPERTY()
  ATPSHud* HUD;

  UPROPERTY(
    VisibleAnywhere
  )
  bool IsUIModeActive = false;

  virtual void SetupInputComponent() override;
  virtual void SaveGame();
  virtual void LoadGame();
  virtual void UpdateTargetPointFromCenterScreen();

protected:
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
};
