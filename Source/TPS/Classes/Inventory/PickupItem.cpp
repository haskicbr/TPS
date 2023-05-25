#include "PickupItem.h"
#include "InventoryComponent.h"
#include "Characters/CharacterBase.h"
#include "Weapon/WeaponBase.h"

APickupItem::APickupItem()
{
  PrimaryActorTick.bCanEverTick = false;

  DefaultRoot = CreateDefaultSubobject<USceneComponent>(
    TEXT(
      "DefaultRoot"
    )
  );

  StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(
    TEXT(
      "StaticMeshComponent"
    )
  );

  StaticMesh->SetupAttachment(
    DefaultRoot
  );

  StaticMesh->OnComponentBeginOverlap.AddDynamic(
    this,
    &APickupItem::OnOverlapBegin
  );
  StaticMesh->OnComponentEndOverlap.AddDynamic(
    this,
    &APickupItem::OnOverlapEnd
  );

  StaticMesh->SetCollisionResponseToAllChannels(
    ECollisionResponse::ECR_Overlap
  );
}

void APickupItem::BeginPlay()
{
  Super::BeginPlay();
}

void APickupItem::OnOverlapEnd(
  UPrimitiveComponent* OverlappedComponent,
  AActor* OtherActor,
  UPrimitiveComponent* OtherComp,
  int32 OtherBodyIndex
)
{
  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    __FUNCTION__
  );
}

void APickupItem::OnOverlapBegin(
  UPrimitiveComponent* OverlappedComponent,
  AActor* OtherActor,
  UPrimitiveComponent* OtherComponent,
  int32 OtherBodyIndex,
  bool bFromSweep,
  const FHitResult& Hit
)
{
  ACharacterBase* CharacterBase = Cast<ACharacterBase>(
    OtherActor
  );

  if (CharacterBase && InventoryItem)
  {
    if (InventoryItem->InventoryType == EInventoryItemType::WeaponRange)
    {
      this->InventoryItem = InventoryItem;

      CharacterBase->GetMesh()->GetSocketByName(
        CharacterBase->WeaponMainSocketName
      );

      AActor* InventoryActor = GetWorld()->SpawnActor(
        InventoryItem->ActorInWorld
      );

      AWeaponBase* Weapon = Cast<AWeaponBase>(
        InventoryActor
      );

      const FAttachmentTransformRules AttachRules = FAttachmentTransformRules(
        EAttachmentRule::KeepRelative,
        false
      );
      InventoryActor->AttachToComponent(
        CharacterBase->GetMesh(),
        AttachRules,
        CharacterBase->WeaponMainSocketName
      );

      if (Weapon)
      {
        CharacterBase->Weapon = Weapon;
      }
    }

    CharacterBase->InventoryComponent->AddItem(
      InventoryItem
    );

    Destroy();
  }
}
