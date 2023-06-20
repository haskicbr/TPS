// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventoryItemWidget.h"

void UInventoryWidget::UpdateInventory()
{
  InventoryGrid->ClearChildren();

  InventoryGrid->SetSlotPadding(
    FMargin(
      10
    )
  );

  for (int Row = 1; Row <= 10; Row++)
  {
    for (int Column = 1; Column <= 10; Column++)
    {
      if (InventorySlotClass)
      {
        UInventorySlotWidget* InventorySlot = CreateWidget<UInventorySlotWidget>(
          GetWorld(),
          InventorySlotClass
        );

        InventorySlots.Add(FVector2d(Row, Column), InventorySlot);

        InventoryGrid->AddChildToUniformGrid(
          InventorySlot,
          Row,
          Column
        );
      }
    }
  }
}

void UInventoryWidget::NativeConstruct()
{
  Super::NativeConstruct();
  UpdateInventory();
}
