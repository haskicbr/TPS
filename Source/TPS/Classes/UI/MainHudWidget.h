#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


#include "MainHudWidget.generated.h"

UCLASS()
class TPS_API UMainHudWidget : public UUserWidget
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, meta = (BindWidget))
  UProgressBar* HealthBar;

  UPROPERTY(EditAnywhere, meta = (BindWidget))
  UTextBlock* HealthValue;


};
