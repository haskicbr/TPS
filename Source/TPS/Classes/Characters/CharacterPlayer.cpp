#include "Characters/CharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "Weapon/WeaponBase.h"


void ACharacterPlayer::BeginPlay()
{
  Super::BeginPlay();
  GetWorldTimerManager().SetTimer(TimerHandleTraceInteractable, this, &ACharacterPlayer::UpdateInteractTrace, 0.1, true);
}

void ACharacterPlayer::Tick(float DeltaSeconds)
{
  Super::Tick(
    DeltaSeconds
  );

  if (!PlayerController)
  {
    return;
  }

  UpdateAudioListener();

  if (PlayerController->TargetHitFromCenterScreen)
  {
    if (AActor* TraceActor = PlayerController->TargetHitFromCenterScreen->GetActor())
    {
      GEngine->AddOnScreenDebugMessage(
        -1,
        4.5f,
        FColor::Red,
        TraceActor->GetClass()->GetName()
      );
    }
  }
}


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

  PlayerController = Cast<ATPSController>(
    GetController()
  );
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

void ACharacterPlayer::UpdateInteractTrace()
{
  ActorInteractable = nullptr;

  FHitResult TraceHit;

  FVector StartTrace = CameraComponent->GetComponentLocation();
  FVector EndTrace = StartTrace + CameraComponent->GetForwardVector() * 175;

  FCollisionQueryParams CollisionQueryParams;

  CollisionQueryParams.AddIgnoredActor(
    this
  );

  DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, 0.3);

  GetWorld()->LineTraceSingleByChannel(
    TraceHit,
    StartTrace,
    EndTrace,
    ECollisionChannel::ECC_WorldDynamic,
    CollisionQueryParams
  );

  DrawDebugSphere(
    GetWorld(),
    EndTrace,
    5,
    5,
    FColor::Red,
    false,
    0.3
  );

  if (TraceHit.bBlockingHit)
  {
    if (TraceHit.GetActor())
    {
      ActorInteractable = TraceHit.GetActor();

      DrawDebugSphere(
        GetWorld(),
        EndTrace,
        5,
        5,
        FColor::Green,
        false,
        0.3
      );
    }
  }
}

void ACharacterPlayer::ActorInteract()
{
  if (!ActorInteractable)
  {
    return;
  }

  if (Cast<APawn>(
    ActorInteractable
  ))
  {
    PlayerController->Possess(
      Cast<APawn>(
        ActorInteractable
      )
    );
  }

  ActorInteractable = nullptr;
}

void ACharacterPlayer::UpdateAudioListener() const
{
  if(PlayerController && CameraComponent)
  {
    PlayerController->SetAudioListenerOverride(
      GetRootComponent(),
      FVector(
        0,
        0,
        2
      ),
      GetActorRotation() * -1 + CameraComponent->GetComponentRotation()
    );
  }
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
  check(PlayerInputComponent);

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

  InputComponent->BindAction(
    "Fire",
    IE_Pressed,
    this,
    &ACharacterPlayer::ActorInteract
  );
}
