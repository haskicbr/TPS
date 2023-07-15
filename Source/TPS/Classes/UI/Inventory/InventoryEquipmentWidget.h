#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Inventory/InventoryItem.h"
#include "InventoryEquipmentWidget.generated.h"


UCLASS()
class TPS_API UInventoryEquipmentWidget : public UUserWidget
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

