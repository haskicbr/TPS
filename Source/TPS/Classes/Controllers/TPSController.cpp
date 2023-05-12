#include "./TPSController.h"
#include "Characters/CharacterPlayer.h"
#include "Components/InputComponent.h"

ATPSController::ATPSController()
{
  PrimaryActorTick.bCanEverTick = true;
  PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATPSController::SetupInputComponent()
{
  Super::SetupInputComponent();

  check(InputComponent);

  InputComponent->BindAxis("MoveForward", this, &ATPSController::MoveForward);
  InputComponent->BindAxis("MoveRight", this, &ATPSController::MoveRight);
  InputComponent->BindAxis("Turn", this, &ATPSController::Turn);
  InputComponent->BindAxis("LookUp", this, &ATPSController::LookUp);
  InputComponent->BindAction("Jump", IE_Pressed, this, &ATPSController::Jump);
  InputComponent->BindAction("Crouch", IE_Pressed, this, &ATPSController::Jump);
}

void ATPSController::BeginPlay()
{
  Super::BeginPlay();
  ControlledCharacter = Cast<ACharacterPlayer>(GetCharacter());
}

void ATPSController::MoveForward(float Value)
{
  UE_LOG(LogTemp, Warning, TEXT("The integer value is: %f"), Value);
  ControlledCharacter->MoveForward(Value);
}

void ATPSController::MoveRight(float Value)
{
  UE_LOG(LogTemp, Warning, TEXT("The integer value is: %f"), Value);
  ControlledCharacter->MoveRight(Value);
}

void ATPSController::Turn(float Value)
{
  ControlledCharacter->Turn(Value);
}

void ATPSController::LookUp(float Value)
{
  ControlledCharacter->LookUp(Value);
}

void ATPSController::Jump()
{
  ControlledCharacter->Jump();
}
