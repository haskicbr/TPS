#include "TPSHud.h"
#include "TestWidget.h"
#include "Blueprint/UserWidget.h"
#include "Characters/CharacterBase.h"
#include "Characters/CharacterPlayer.h"
#include "Controllers/TPSController.h"
#include "Kismet/GameplayStatics.h"

void ATPSHud::BeginPlay()
{
  Super::BeginPlay();

  Controller = Cast<ATPSController>(
    GetOwningPlayerController()
  );
  Character = Controller->ControlledCharacter;
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
  InventoryWidget->InventoryComponent = Character->InventoryComponent;

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

void ATPSHud::ChangeVisible()
{
  IsInventoryOpen = !IsInventoryOpen;

  if (!InventoryWidget)
  {
    return;
  }

  if (IsInventoryOpen)
  {
    Controller->IsUIModeActive = false;
    Controller->SetShowMouseCursor(false);
    Controller->SetInputMode(FInputModeGameOnly());
    InventoryWidget->RemoveFromParent();
    Controller->EnableInput(Controller);
  }
  else
  {
    Controller->IsUIModeActive = true;
    Controller->SetInputMode(FInputModeUIOnly());

    Controller->SetShowMouseCursor(true);
    InventoryWidget->AddToViewport();
  }
}
