// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "TestWidget.generated.h"


UCLASS()
class TPS_API UTestWidget : public UUserWidget
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, meta = (BindWidget))
  UTextBlock* TestTextField;
};
