// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/ScaleBox.h"
#include "InventoryItemWidget.h"
#include "InventorySlotWidget.generated.h"

UCLASS()
class TPS_API UInventorySlotWidget : public UUserWidget
{
  GENERATED_BODY()

public:
  UPROPERTY(
    EditAnywhere,
    meta = (BindWidget)
  )
  UScaleBox* InventoryItemContainer;

protected:
  virtual bool NativeOnDrop(
    const FGeometry& InGeometry,
    const FDragDropEvent& InDragDropEvent,
    UDragDropOperation* InOperation
  ) override;
};


inline bool UInventorySlotWidget::NativeOnDrop(
  const FGeometry& InGeometry,
  const FDragDropEvent& InDragDropEvent,
  UDragDropOperation* InOperation
)
{
  UInventoryItemWidget* DragInventoryItemWidget = Cast<UInventoryItemWidget>(
    InOperation->Payload
  );

  DragInventoryItemWidget->RemoveFromParent();

  InventoryItemContainer->AddChild(DragInventoryItemWidget);

  return Super::NativeOnDrop(
    InGeometry,
    InDragDropEvent,
    InOperation
  );
}



