#include "TPSGameState.h"

#include "Components/Inventory/InventoryItemParams.h"
#include "Components/Inventory/InventoryWorldObjectParams.h"
#include "Engine/DataTable.h"

void ATPSGameState::BeginPlay()
{
  Super::BeginPlay();

  FillInventoryData();
}


void ATPSGameState::FillInventoryData()
{
  UDataTable* DT;

  DT = Cast<UDataTable>(
    InventoryWorldObjectsTablePath.ResolveObject()
  );

  if (!DT)
  {
    DT = Cast<UDataTable>(
      InventoryWorldObjectsTablePath.TryLoad()
    );
  }

  TArray<FInventoryWorldObjectParams*> AllRows;

  DT->GetAllRows<FInventoryWorldObjectParams>(
    TEXT(
      "FillInventoryDataContext"
    ),
    AllRows
  );

  for (FInventoryWorldObjectParams* Row : AllRows)
  {
    GEngine->AddOnScreenDebugMessage(
     -1,
     4.5f,
     FColor::Yellow,
     Row->PickupItem->StaticClass()->GetName()
     );
    // ....
  }
}
