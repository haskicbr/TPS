// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainHudWidget.h"
#include "TestWidget.h"
#include "GameFramework/HUD.h"
#include "TPSHud.generated.h"


UCLASS()
class TPS_API ATPSHud : public AHUD
{
  GENERATED_BODY()
  virtual void BeginPlay() override;
  virtual void Tick(float DeltaSeconds) override;

public:
  UPROPERTY()
  class UTestWidget* CharacterOverlay;

  UPROPERTY()
  class UMainHudWidget* MainHudWidget;

  UPROPERTY()
  float CurrentTime = 0.0;


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

  UFUNCTION(BlueprintCallable, Category="Widgets")
  void InitialWidgets();

};
