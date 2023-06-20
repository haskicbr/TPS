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
    "Fire",
    IE_Pressed,
    this,
    &ATPSController::Fire
  );


  InputComponent->BindAxis(
    "MoveForward",
    this,
    &ATPSController::MoveForward
  );

  InputComponent->BindAxis(
    "MoveRight",
    this,
    &ATPSController::MoveRight
  );

  InputComponent->BindAxis(
    "Turn",
    this,
    &ATPSController::Turn
  );

  InputComponent->BindAxis(
    "LookUp",
    this,
    &ATPSController::LookUp
  );

  InputComponent->BindAction(
    "Jump",
    IE_Pressed,
    this,
    &ATPSController::Jump
  );

  InputComponent->BindAction(
    "Crouch",
    IE_Pressed,
    this,
    &ATPSController::Jump
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


  ControlledCharacter->AttributesComponent->OnChangeHealth.AddDynamic(
    HUD,
    &ATPSHud::UpdateHealth
  );
}


void ATPSController::MoveForward(float Value)
{
  if (IsUIModeActive)
  {
    return;
  }

  float mouseX;
  float mouseY;
  GetMousePosition(
    mouseX,
    mouseY
  );

  GEngine->AddOnScreenDebugMessage(
    12,
    4.5f,
    FColor::Red,
    FString::FromInt(
      mouseX
    )
  );
  GEngine->AddOnScreenDebugMessage(
    13,
    4.5f,
    FColor::Red,
    FString::FromInt(
      mouseY
    )
  );

  ControlledCharacter->MoveForward(
    Value
  );
}

void ATPSController::MoveRight(float Value)
{
  if (IsUIModeActive)
  {
    return;
  }

  ControlledCharacter->MoveRight(
    Value
  );
}

void ATPSController::Turn(float Value)
{
  if (IsUIModeActive)
  {
    return;
  }

  ControlledCharacter->Turn(
    Value
  );
}

void ATPSController::LookUp(float Value)
{
  if (IsUIModeActive)
  {
    return;
  }

  ControlledCharacter->LookUp(
    Value
  );
}

void ATPSController::Jump()
{
  if (IsUIModeActive)
  {
    return;
  }

  ControlledCharacter->Jump();
}

void ATPSController::Fire()
{
  if (IsUIModeActive)
  {
    return;
  }


  if (ControlledCharacter->Weapon)
  {
    const USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

    if (ControlledCharacter)
    {
      SkeletalMeshComponent = Cast<USkeletalMeshComponent>(
        ControlledCharacter->GetComponentByClass(
          USkeletalMeshComponent::StaticClass()
        )
      );
    }

    if (SkeletalMeshComponent)
    {
      UCameraComponent* CameraComponent = Cast<UCameraComponent>(
        ControlledCharacter->GetComponentByClass(
          UCameraComponent::StaticClass()
        )
      );

      ControlledCharacter->Weapon->Fire(
        TargetPointFromCenterScreen
      );
    }
  }

  //UGameplayStatics::ApplyDamage(GetWorld(), )
}

void ATPSController::SaveGame()
{
  USaveGameData* TestSaveGame = Cast<USaveGameData>(
    UGameplayStatics::CreateSaveGameObject(
      USaveGameData::StaticClass()
    )
  );
  TestSaveGame->CharacterTransform = ControlledCharacter->GetTransform();


  UInventoryItem* InventoryItem = NewObject<UInventoryItem>();
  InventoryItem->Count += 1;
  InventoryItem->TimeSpan = FDateTime::Now().GetTimeOfDay().ToString();

  TestSaveGame->InventoryItem = InventoryItem;

  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    TestSaveGame->InventoryItem->TimeSpan
  );
}

void ATPSController::LoadGame()
{
  UObject* ClassPackage = ANY_PACKAGE;

  const AActor* ObjectToSpawn = FindObject<AActor>(
    ClassPackage,
    TEXT(
      "Game/Main/Blueprints/BP_TriggerLight"
    )
  );

  FActorSpawnParameters SpawnParameters;


  /*const ConstructorHelpers::FObjectFinder<UBlueprint> BlueprintClass(TEXT("Blueprint'/Game/Main/Blueprints/BP_TriggerLight'"));
  auto mBlueprintClass = static_cast<UClass*>(BlueprintClass.Object->GeneratedClass);*/

  const FString SpawnObjectName = "testObject" + FGuid::NewGuid().ToString();

  SpawnParameters.Owner = GetOwner();
  SpawnParameters.Instigator = nullptr;
  SpawnParameters.Name = FName(
    SpawnObjectName
  );

  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    ObjectToSpawn->StaticClass()->GetName()
  );


  GetWorld()->SpawnActor<ATriggeredLight>(
    ATriggeredLight::StaticClass(),
    ControlledCharacter->GetActorLocation() + ControlledCharacter->GetActorForwardVector() * 2,
    FRotator(
      0,
      0,
      0
    ),
    SpawnParameters
  );

  return;


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
    ControlledCharacter->SetActorTransform(
      TestSaveGame->CharacterTransform
    );

    GEngine->AddOnScreenDebugMessage(
      -1,
      4.5f,
      FColor::Purple,
      TestSaveGame->InventoryItem->TimeSpan
    );
  }
}


void ATPSController::Tick(const float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );

  UpdateTargetPointFromCenterScreen();
  UpdateAudioListener();
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
  }
  else
  {
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

void ATPSController::UpdateAudioListener()
{
  SetAudioListenerOverride(
    ControlledCharacter->GetRootComponent(),
    FVector(
      0,
      0,
      2
    ),
    ControlledCharacter->GetActorRotation() * -1 + ControlledCharacter->CameraComponent->GetComponentRotation()
  );
}
