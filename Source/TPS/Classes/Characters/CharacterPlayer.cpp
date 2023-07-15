#include "Characters/CharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "Weapon/WeaponBase.h"

ACharacterPlayer::ACharacterPlayer()
{
  PrimaryActorTick.bCanEverTick = true;
  CameraComponent = CreateDefaultSubobject<UCameraComponent>(
    TEXT(
      "CameraComponent"
    )
  );

  SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(
    "SpringArmComponent"
  );

  SpringArmComponent->SetupAttachment(
    GetRootComponent()
  );
  SpringArmComponent->TargetArmLength = 600.f;

  CameraComponent->SetupAttachment(
    SpringArmComponent
  );

  SpringArmComponent->bUsePawnControlRotation = true;

  static ConstructorHelpers::FObjectFinder<UAnimMontage> MontageAsset(
    TEXT(
      "Montage'/Game/Main/Blueprints/AM_Test'"
    )
  );
  Montage = MontageAsset.Object;
}

void ACharacterPlayer::MoveForward(float ForwardAxis)
{
  AddMovementInput(
    GetActorForwardVector(),
    ForwardAxis
  );
}

void ACharacterPlayer::MoveRight(float RightAxis)
{
  AddMovementInput(
    GetActorRightVector(),
    RightAxis
  );
}

void ACharacterPlayer::Turn(float Axis)
{
  AddControllerYawInput(
    Axis
  );
}

void ACharacterPlayer::LookUp(float Axis)
{
  AddControllerPitchInput(
    Axis
  );
}

void ACharacterPlayer::PossessedBy(AController* NewController)
{
  Super::PossessedBy(
    NewController
  );
  PlayerController = Cast<ATPSController>(
    NewController
  );
}

void ACharacterPlayer::PrintFire()
{
  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Red,
    __FUNCTION__
  );
}

void ACharacterPlayer::Fire()
{
  if (PlayerController->IsUIModeActive)
  {
    return;
  }

  if (this->Weapon)
  {
    const USkeletalMeshComponent* SkeletalMeshComponent = nullptr;


    SkeletalMeshComponent = Cast<USkeletalMeshComponent>(
      this->GetComponentByClass(
        USkeletalMeshComponent::StaticClass()
      )
    );


    if (SkeletalMeshComponent)
    {
      CameraComponent = Cast<UCameraComponent>(
        this->GetComponentByClass(
          UCameraComponent::StaticClass()
        )
      );

      this->Weapon->Fire(
        PlayerController->TargetPointFromCenterScreen
      );
    }
  }
}

void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(
    PlayerInputComponent
  );

  PlayerInputComponent->BindAction(
    "Fire",
    IE_Pressed,
    this,
    &ACharacterPlayer::PrintFire
  );


  InputComponent->BindAction(
    "Fire",
    IE_Pressed,
    this,
    &ACharacterPlayer::Fire
  );


  InputComponent->BindAxis(
    "MoveForward",
    this,
    &ACharacterPlayer::MoveForward
  );

  InputComponent->BindAxis(
    "MoveRight",
    this,
    &ACharacterPlayer::MoveRight
  );

  InputComponent->BindAxis(
    "Turn",
    this,
    &ACharacterPlayer::Turn
  );

  InputComponent->BindAxis(
    "LookUp",
    this,
    &ACharacterPlayer::LookUp
  );

  InputComponent->BindAction(
    "Jump",
    IE_Pressed,
    this,
    &ACharacterPlayer::Jump
  );
}
