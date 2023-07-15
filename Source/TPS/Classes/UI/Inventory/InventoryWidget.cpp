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

  for (int Row = 1; Row <= 3; Row++)
  {
    for (int Column = 1; Column <=3 ; Column++)
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


  auto InventorySlotsArray = InventorySlots.Array();
  auto InventoryItemsArray = InventoryComponent->Inventory.Array();


  int ArrayIterator = 0;
  for (const TTuple<FString, UInventoryItem*> InventoryItem : InventoryItemsArray)
  {
    InventoryItem.Value->Count;

    if (InventorySlotsArray.IsValidIndex(
      ArrayIterator
    ))
    {
      const UInventorySlotWidget* SlotWidget = InventorySlotsArray[ArrayIterator].Value;

      UInventoryItemWidget* InventoryItemWidget = CreateWidget<UInventoryItemWidget>(
        GetWorld(),
        InventoryItemClass
      );
      InventoryItemWidget->SetInventoryItem(InventoryItem.Value);

      SlotWidget->InventoryItemContainer->AddChild(
        InventoryItemWidget
      );
    }
    ArrayIterator++;
  }
}


void UInventoryWidget::NativeConstruct()
{
  Super::NativeConstruct();
  
  if (!bIsInitialised)
  {
    UpdateInventory();
    bIsInitialised = true;
  }

}
