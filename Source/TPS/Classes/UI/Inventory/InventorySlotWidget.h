// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "InventorySlotWidget.generated.h"

UCLASS()
class TPS_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
  virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;


  virtual void NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
  virtual FReply NativeOnMouseButtonDown(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent
) override;

  virtual void NativeOnDragDetected
  (
      const FGeometry & InGeometry,
      const FPointerEvent & InMouseEvent,
      UDragDropOperation *& OutOperation
  ) override;


  virtual FReply NativeOnMouseButtonDoubleClick(
      const FGeometry& InGeometry,
      const FPointerEvent& InMouseEvent
    ) override;
};


inline bool UInventorySlotWidget::NativeOnDrop(
  const FGeometry& InGeometry,
  const FDragDropEvent& InDragDropEvent,
  UDragDropOperation* InOperation
)
{

  UWidget * DragSlot = Cast<UWidget>(InOperation->Payload);
  DragSlot->RemoveFromParent();

  return Super::NativeOnDrop(
    InGeometry,
    InDragDropEvent,
    InOperation
  );
}

inline void UInventorySlotWidget::NativeOnDragCancelled(
  const FDragDropEvent& InDragDropEvent,
  UDragDropOperation* InOperation
)
{

  SetVisibility(ESlateVisibility::Visible);

  Super::NativeOnDragCancelled(
    InDragDropEvent,
    InOperation
  );
}



inline FReply UInventorySlotWidget::NativeOnMouseButtonDown(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent
)
{
  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    __FUNCTION__
  );

  const FKey MouseButton = InMouseEvent.GetEffectingButton();

  if (MouseButton == EKeys::RightMouseButton)
  {
    // TODO: Show ContextMenu widget
    return FReply::Handled();
  }

  FEventReply Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);
  return Reply.NativeReply;
}

inline void UInventorySlotWidget::NativeOnDragDetected(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent,
  UDragDropOperation*& OutOperation
)
{
  UDragDropOperation * DragDropOperation  = Cast<UDragDropOperation>(UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass()));

  DragDropOperation->Payload = this;
  DragDropOperation->Pivot = EDragPivot::MouseDown;

  OutOperation = DragDropOperation;

  SetVisibility(ESlateVisibility::Hidden);
}

inline FReply UInventorySlotWidget::NativeOnMouseButtonDoubleClick(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent
)
{
  GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Purple, __FUNCTION__);

  return Super::NativeOnMouseButtonDoubleClick(
    InGeometry,
    InMouseEvent
  );
}
