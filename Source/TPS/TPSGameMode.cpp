#include "TPSGameMode.h"
#include "Characters/CharacterPlayer.h"
#include "Controllers/TPSController.h"
#include "UI/TPSHud.h"
#include "UObject/ConstructorHelpers.h"

ATPSGameMode::ATPSGameMode()
{
	static ConstructorHelpers::FClassFinder<ACharacterBase> PlayerPawnBPClass(TEXT("/Game/Main/Blueprints/Characters/BP_CharacterPlayer"));
  static ConstructorHelpers::FClassFinder<ATPSHud> HudClass(TEXT("/Game/Main/Blueprints/Game/BP_TPSHud"));



	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

  //DefaultPawnClass = ACharacterPlayer::StaticClass();
  PlayerControllerClass = ATPSController::StaticClass();
  HUDClass = HudClass.Class;
}
