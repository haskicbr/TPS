// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSHud.h"

#include "TestWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ATPSHud::BeginPlay()
{
  Super::BeginPlay();

  if (CharacterOverlay)
  {
  }
}

void ATPSHud::Tick(float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );

  CurrentTime += DeltaSeconds;


  if (CharacterOverlay && MainHudWidget)
  {
    auto Text = FText::FromString(
      FString::SanitizeFloat(
        CurrentTime
      )
    );
    CharacterOverlay->TestTextField->SetText(
      Text
    );

    MainHudWidget->HealthBar->SetPercent(1.0);
  }
}


void ATPSHud::InitialWidgets()
{
  CharacterOverlay = CreateWidget<UTestWidget>(
    GetOwningPlayerController(),
    CharacterOverlayClass
  );


  MainHudWidget = CreateWidget<UMainHudWidget>(
    GetOwningPlayerController(),
    MainHudWidgetClass
  );

  if (CharacterOverlay)
  {
    CharacterOverlay->AddToViewport();
    MainHudWidget->AddToViewport();
  }
}
