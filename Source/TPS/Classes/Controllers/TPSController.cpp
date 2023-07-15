#include "./TPSController.h"

#include "ARTypes.h"
#include "Camera/CameraComponent.h"
#include "Characters/CharacterPlayer.h"
#include "Components/AttributesComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Light/TriggeredLight.h"
#include "SaveGame/SaveGameData.h"
#include "UI/TPSHud.h"
#include "Weapon/WeaponBase.h"

ATPSController::ATPSController()
{
  PrimaryActorTick.bCanEverTick = true;
  PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATPSController::SetupInputComponent()
{
  Super::SetupInputComponent();

  check(
    InputComponent
  );

  InputComponent->BindAction(
    "SaveGame",
    IE_Pressed,
    this,
    &ATPSController::SaveGame
  );

  InputComponent->BindAction(
    "LoadGame",
    IE_Pressed,
    this,
    &ATPSController::LoadGame
  );
}

void ATPSController::BeginPlay()
{
  Super::BeginPlay();

  ControlledCharacter = Cast<ACharacterPlayer>(
    GetCharacter()
  );

  ControlledCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;

  HUD = Cast<ATPSHud>(
    GetHUD()
  );

  InputComponent->BindAction(
    "Inventory",
    IE_Pressed,
    HUD,
    &ATPSHud::ChangeVisible
  );

  HUD->InitialWidgets();

  ControlledCharacter->AttributesComponent->OnChangeHealth.AddDynamic(
    HUD,
    &ATPSHud::UpdateHealth
  );
}

void ATPSController::SaveGame()
{
  ControlledCharacter->GetMesh()->SetSimulatePhysics(
    !ControlledCharacter->GetMesh()->IsSimulatingPhysics()
  );

  USaveGameData* TestSaveGame = Cast<USaveGameData>(
    UGameplayStatics::CreateSaveGameObject(
      USaveGameData::StaticClass()
    )
  );

  auto Obj = FInventoryItemParams();
  Obj.Count = 1000;

  Obj.InitialActor = ACharacterBase::StaticClass();

  TestSaveGame->Objects.Add(
    Obj
  );

  for (auto Obj123 : TestSaveGame->Objects)
  {
    GEngine->AddOnScreenDebugMessage(
      -1,
      4.5f,
      FColor::Red,
      FString::FromInt(
        Obj123.Count
      )
    );
  }

  UGameplayStatics::SaveGameToSlot(
    TestSaveGame,
    FString(
      "test"
    ),
    1
  );
}

void ATPSController::LoadGame()
{
  GEngine->AddOnScreenDebugMessage(
    -1,
    1000,
    FColor::Red,
    "qweqweqweqweqweqwe"
  );
  USaveGameData* TestSaveGame = Cast<USaveGameData>(
    UGameplayStatics::LoadGameFromSlot(
      FString(
        "test"
      ),
      1
    )
  );

  if (TestSaveGame)
  {
    for (auto Obj : TestSaveGame->Objects)
    {
      GEngine->AddOnScreenDebugMessage(
        -1,
        4.5f,
        FColor::Red,
        FString::FromInt(
          Obj.Count
        )
      );

      GetWorld()->SpawnActor<AActor>(
        Obj.InitialActor,
        ControlledCharacter->GetActorLocation(),
        ControlledCharacter->GetActorRotation()
      );
    }
  }
}

void ATPSController::Tick(const float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );

  UpdateTargetPointFromCenterScreen();

}

void ATPSController::UpdateTargetPointFromCenterScreen()
{
  UCameraComponent* CameraComponent = Cast<UCameraComponent>(
    ControlledCharacter->GetComponentByClass(
      UCameraComponent::StaticClass()
    )
  );

  FHitResult TraceHit;

  FCollisionQueryParams CollisionParams;

  FVector2d ViewportSize;
  GEngine->GameViewport->GetViewportSize(
    ViewportSize
  );

  FVector2D CrossHairLocation(
    ViewportSize.X / 2.f,
    ViewportSize.Y / 2.f
  );
  FVector WorldLocation;
  FVector WorldDirection;


  UGameplayStatics::DeprojectScreenToWorld(
    this,
    CrossHairLocation,
    WorldLocation,
    WorldDirection
  );

  FVector StartTrace = WorldLocation;
  FVector EndTrace = StartTrace + WorldDirection * 80000.f;

  FCollisionQueryParams CollisionQueryParams;

  CollisionQueryParams.AddIgnoredActor(
    ControlledCharacter
  );

  GetWorld()->LineTraceSingleByChannel(
    TraceHit,
    StartTrace,
    EndTrace,
    ECollisionChannel::ECC_WorldStatic,
    CollisionQueryParams
  );

  if (TraceHit.bBlockingHit)
  {
    TargetPointFromCenterScreen = TraceHit.ImpactPoint;
    TargetHitFromCenterScreen = &TraceHit;
  }
  else
  {
    TargetHitFromCenterScreen = nullptr;
    //TargetPointFromCenterScreen = WorldLocation + CameraComponent->GetForwardVector() * 80000.f;
    TargetPointFromCenterScreen = EndTrace;
  }

  DrawDebugLine(
    GetWorld(),
    StartTrace,
    TargetPointFromCenterScreen,
    FColor::Red,
    false,
    0.05
  );
}


