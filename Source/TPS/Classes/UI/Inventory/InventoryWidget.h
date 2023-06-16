#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "InventoryWidget.generated.h"


UCLASS()
class TPS_API UInventoryWidget : public UUserWidget
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, meta = (BindWidget))
  UUniformGridPanel* InventoryGrid;
};
