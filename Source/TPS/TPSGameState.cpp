#include "TPSGameState.h"

#include "Components/Inventory/InventoryItemParams.h"
#include "Components/Inventory/InventoryWorldObjectParams.h"
#include "Engine/DataTable.h"

void ATPSGameState::BeginPlay()
{
  Super::BeginPlay();
}


void ATPSGameState::FillInventoryData()
{
  UDataTable* DT;

  DT = Cast<UDataTable>(
    InventoryWorldObjectsTablePath.ResolveObject()
  );

  if (DT)
  {
  }
  else
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
    // ....
  }
}
