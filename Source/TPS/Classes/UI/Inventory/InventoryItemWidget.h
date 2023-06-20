#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemWidget.generated.h"


UCLASS()
class TPS_API UInventoryItemWidget : public UUserWidget
{
  GENERATED_BODY()

protected:
  /*virtual FReply NativeOnMouseButtonDoubleClick(
    const FGeometry& InGeometry,
    const FPointerEvent& InMouseEvent
  ) override;

  virtual FReply NativeOnMouseButtonDown(
    const FGeometry& InGeometry,
    const FPointerEvent& InMouseEvent
  ) override;

  virtual void NativeOnDragDetected(
    const FGeometry& InGeometry,
    const FPointerEvent& InMouseEvent,
    UDragDropOperation*& OutOperation
  ) override;*/
};
