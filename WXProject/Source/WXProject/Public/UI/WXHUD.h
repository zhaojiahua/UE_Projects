// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WXHUD.generated.h"

class UWXUserWidget;
class UWXWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;
struct FWidgetContrllerParam;
UCLASS()
class WXPROJECT_API AWXHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<UWXUserWidget> overlayWidget;
	UPROPERTY()
	TObjectPtr<UWXWidgetController> overlayWidgetController;

	UWXWidgetController* GetOverlayWidgetController(const FWidgetContrllerParam& wctrlParams);
	void InitOverlayHUD(APlayerController* inpc, APlayerState* inps, UAbilitySystemComponent* inasc, UAttributeSet* inas);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget>overlayWidgetClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UWXWidgetController>overlayWidgetControllerClass;
};
