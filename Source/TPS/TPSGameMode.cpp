#include "TPSGameMode.h"

#include "TPSGameState.h"
#include "Characters/CharacterPlayer.h"
#include "Controllers/TPSController.h"
#include "UI/TPSHud.h"
#include "UObject/ConstructorHelpers.h"

ATPSGameMode::ATPSGameMode()
{
	static ConstructorHelpers::FClassFinder<ACharacterBase> PlayerPawnBPClass(TEXT("/Game/Main/Blueprints/Characters/Player/BP_CharacterPlayerFirstPerson"));
  static ConstructorHelpers::FClassFinder<ATPSHud> HudClass(TEXT("/Game/Main/Blueprints/Game/BP_TPSHud"));
  static ConstructorHelpers::FClassFinder<ATPSGameState> GameStateInitial(TEXT("/Game/Main/Blueprints/Game/BP_GameState"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

  //DefaultPawnClass = ACharacterPlayer::StaticClass();
  PlayerControllerClass = ATPSController::StaticClass();
  HUDClass = HudClass.Class;

  GameStateClass = GameStateInitial.Class;
}
