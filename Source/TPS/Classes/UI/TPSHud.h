// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainHudWidget.h"
#include "TestWidget.h"
#include "GameFramework/HUD.h"
#include "Inventory/InventoryWidget.h"
#include "TPSHud.generated.h"


UCLASS()
class TPS_API ATPSHud : public AHUD
{
  GENERATED_BODY()
  virtual void Tick(float DeltaSeconds) override;

public:
  UPROPERTY()
  class UTestWidget* CharacterOverlay;

  UPROPERTY()
  class UMainHudWidget* MainHudWidget;

  UPROPERTY()
  class UInventoryWidget* InventoryWidget;

  UPROPERTY()
  class ATPSController* Controller;

  UPROPERTY()
  TSoftObjectPtr<class ACharacterPlayer> Character;


  UPROPERTY()
  float CurrentTime = 0.0;

  UPROPERTY()
  bool IsInventoryOpen = false;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadWrite,
    Category= "Player Overlay"
  )
  TSubclassOf<UTestWidget> CharacterOverlayClass;

  UPROPERTY(
    EditAnywhere,
    BlueprintReadWrite,
    Category= "Player Hud Widget"
  )
  TSubclassOf<UMainHudWidget> MainHudWidgetClass;


  UPROPERTY(
    EditAnywhere,
    BlueprintReadWrite,
    Category= "Inventory Widget"
  )
  TSubclassOf<UInventoryWidget> InventoryWidgetClass;

  UFUNCTION(BlueprintCallable, Category="Widgets")
  void InitialWidgets();

  UFUNCTION()
  void UpdateHealth(float Health, float MaxHealth) ;

  UFUNCTION()
  void ChangeVisible();

};
