#pragma once
#include "Animation/AnimInstance.h"
#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterBaseAnimInstance.generated.h"

UCLASS()
class TPS_API UCharacterBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
  virtual void NativeBeginPlay() override;
  virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character animation")
  float Speed = 0.0f;


  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character animation")
  bool bIsFalling = false;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character animation")
  bool bIsDead = false;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character animation")
  double DirectionAngle;


private:
  TWeakObjectPtr<class ACharacterBase> CurrentCharacter;


};
