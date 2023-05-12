#include "TPSGameMode.h"
#include "Characters/CharacterPlayer.h"
#include "Controllers/TPSController.h"
#include "UObject/ConstructorHelpers.h"

ATPSGameMode::ATPSGameMode()
{
	static ConstructorHelpers::FClassFinder<ACharacterBase> PlayerPawnBPClass(TEXT("/Game/Main/Blueprints/Characters/BP_CharacterPlayer"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

  //DefaultPawnClass = ACharacterPlayer::StaticClass();
  PlayerControllerClass = ATPSController::StaticClass();
}
