#include "TPSHud.h"
#include "TestWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ATPSHud::BeginPlay()
{
  Super::BeginPlay();
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

  InventoryWidget = CreateWidget<UInventoryWidget>(
    GetOwningPlayerController(),
    InventoryWidgetClass
  );

  if (CharacterOverlay)
  {
    CharacterOverlay->AddToViewport();
    MainHudWidget->AddToViewport();
    InventoryWidget->AddToViewport();
  }
}

void ATPSHud::UpdateHealth(const float Health, const float MaxHealth)
{
  MainHudWidget->HealthBar->SetPercent(
    Health / MaxHealth
  );
  MainHudWidget->HealthValue->SetText(
    FText::FromString(
      FString::SanitizeFloat(
        Health
      )
    )
  );
}

void ATPSHud::ShowInventory()
{
  IsInventoryOpen = !IsInventoryOpen;

  if (!InventoryWidget)
  {
    return;
  }

  if (IsInventoryOpen)
  {
    InventoryWidget->RemoveFromParent();
  }
  else
  {
    InventoryWidget->AddToViewport();
  }
}
