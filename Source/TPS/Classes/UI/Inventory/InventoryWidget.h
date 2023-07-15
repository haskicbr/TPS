#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemWidget.h"
#include "InventorySlotWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/Inventory/InventoryComponent.h"
#include "InventoryWidget.generated.h"


UCLASS()
class TPS_API UInventoryWidget : public UUserWidget
{
  GENERATED_BODY()

public:


  UPROPERTY(VisibleAnywhere)
  bool bIsInitialised = false;


  UPROPERTY(EditAnywhere)
  UInventoryComponent* InventoryComponent;

  UPROPERTY(EditAnywhere, meta = (BindWidget))
  UUniformGridPanel* InventoryGrid;

  UPROPERTY()
  TMap<FVector2D, UInventorySlotWidget*> InventorySlots;

  UPROPERTY(EditAnywhere)
  TSubclassOf<UInventoryItemWidget> InventoryItemClass;

  UPROPERTY(EditAnywhere)
  TSubclassOf<UInventorySlotWidget> InventorySlotClass;


  virtual void NativeConstruct() override;

  void UpdateInventory();
};
