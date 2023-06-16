#include "TestWidget.h"

void UTestWidget::NativeConstruct()
{
  Super::NativeConstruct();


  GEngine->AddOnScreenDebugMessage(
    -1,
    4.5f,
    FColor::Purple,
    __FUNCTION__
  );


}
