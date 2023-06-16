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

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  class ACharacterPlayer* ControlledCharacter;


  UPROPERTY()
  FVector TargetPointFromCenterScreen = FVector();

  UPROPERTY()
  ATPSHud * HUD;


  virtual void SetupInputComponent() override;
  virtual void MoveForward(float Value);
  virtual void MoveRight(float Value);
  virtual void Turn(float Value);
  virtual void LookUp(float Value);
  virtual void Jump();
  virtual void Fire();
  virtual void SaveGame();
  virtual void LoadGame();

  virtual void UpdateTargetPointFromCenterScreen();
  virtual void UpdateAudioListener();

protected:
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;
};
