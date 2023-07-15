#include "InventoryItemWidget.h"

void UInventoryItemWidget::SetInventoryItem(UInventoryItem * Item)
{
  InventoryItem = Item;


  if(IsValid(Item))
  {
    //Icon->SetBrushFromTexture(Item->Icon);
  }
}



FReply UInventoryItemWidget::NativeOnMouseButtonDoubleClick(
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


 void UInventoryItemWidget::NativeOnDragDetected(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent,
  UDragDropOperation*& OutOperation
)
{
  UDragDropOperation* DragDropOperation = Cast<UDragDropOperation>(
    UWidgetBlueprintLibrary::CreateDragDropOperation(
      UDragDropOperation::StaticClass()
    )
  );


  auto DragVisual =   CreateWidget<UInventoryItemWidget>(
    GetWorld(),
    this->StaticClass()
  );

  DragVisual->Icon = this->Icon;

  DragVisual->AddToViewport();

  DragDropOperation->DefaultDragVisual =  DragVisual;
  DragDropOperation->Payload = this;
  DragDropOperation->Pivot = EDragPivot::MouseDown;

  OutOperation = DragDropOperation;

  SetVisibility(
    ESlateVisibility::Hidden
  );
}

 void UInventoryItemWidget::NativeOnDragCancelled(
  const FDragDropEvent& InDragDropEvent,
  UDragDropOperation* InOperation
)
{
  SetVisibility(
    ESlateVisibility::Visible
  );

  Super::NativeOnDragCancelled(
    InDragDropEvent,
    InOperation
  );
}


FReply UInventoryItemWidget::NativeOnMouseButtonDown(
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



  FEventReply Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(
    InMouseEvent,
    this,
    EKeys::LeftMouseButton
  );

  return Reply.NativeReply;
}

