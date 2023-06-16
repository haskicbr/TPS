#include "TriggeredLight.h"
#include "GameFramework/Character.h"

ATriggeredLight::ATriggeredLight()
{
  PrimaryActorTick.bCanEverTick = false;

  DefaultRoot = CreateDefaultSubobject<USceneComponent>(
    TEXT(
      "DefaultRoot"
    )
  );

  SetRootComponent(
    DefaultRoot
  );

  StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(
    TEXT(
      "StaticMeshComponent"
    )
  );

  static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
    TEXT(
      "StaticMesh'/Game/Main/Meshes/Cone'"
    )
  );
  UStaticMesh* Asset = MeshAsset.Object;

  StaticMesh->SetStaticMesh(
    Asset
  );

  PointLight = CreateDefaultSubobject<UPointLightComponent>(
    TEXT(
      "Light"
    )
  );

  PointLight->SetupAttachment(
    StaticMesh
  );
  StaticMesh->SetupAttachment(
    DefaultRoot
  );

  StaticMesh->OnComponentBeginOverlap.AddDynamic(
    this,
    &ATriggeredLight::OnOverlapBegin
  );
  StaticMesh->OnComponentEndOverlap.AddDynamic(
    this,
    &ATriggeredLight::OnOverlapEnd
  );

  StaticMesh->SetCollisionResponseToAllChannels(
    ECollisionResponse::ECR_Overlap
  );
  PointLight->SetVisibility(
    false
  );
}

void ATriggeredLight::OnOverlapBegin(
  UPrimitiveComponent* OverlappedComponent,
  AActor* OtherActor,
  UPrimitiveComponent* OtherComponent,
  int32 OtherBodyIndex,
  bool bFromSweep,
  const FHitResult& Hit
)
{
  const auto PlayerCharacter = Cast<ACharacter>(
    OtherActor
  );

  if (!PlayerCharacter)
  {
    return;
  }

  this->Activate();
}

void ATriggeredLight::OnOverlapEnd(
  UPrimitiveComponent* OverlappedComponent,
  AActor* OtherActor,
  UPrimitiveComponent* OtherComp,
  int32 OtherBodyIndex
)
{
  const auto PlayerCharacter = Cast<ACharacter>(
    OtherActor
  );

  if (!PlayerCharacter)
  {
    return;
  }

  this->Deactivate();
}

void ATriggeredLight::BeginPlay()
{
  Super::BeginPlay();
}

void ATriggeredLight::Activate()
{
  PointLight->SetVisibility(
    true
  );
}

void ATriggeredLight::Deactivate()
{
  PointLight->SetVisibility(
    false
  );
}
