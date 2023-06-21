#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Inventory/InventoryItem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "InventoryItemWidget.generated.h"


UCLASS()
class TPS_API UInventoryItemWidget : public UUserWidget
{
  GENERATED_BODY()

public:
  UPROPERTY(
    EditAnywhere,
    meta = (BindWidget)
  )
  UImage* Icon;

  UPROPERTY(
    EditAnywhere,
    meta = (BindWidget)
  )
  UTextBlock* DescriptionBlock;


  UPROPERTY(
    VisibleAnywhere
  )
  UInventoryItem* InventoryItem;

  UFUNCTION()
  virtual void SetInventoryItem(UInventoryItem* Item);


  virtual FReply NativeOnMouseButtonDoubleClick(
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
  ) override;

  virtual void NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;



  /*virtual FReply NativeOnMouseButtonDoubleClick(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent
) override;

virtual FReply NativeOnMouseButtonDown(
  const FGeometry& InGeometry,
  const FPointerEvent& InMouseEvent
) override;
*/


};

