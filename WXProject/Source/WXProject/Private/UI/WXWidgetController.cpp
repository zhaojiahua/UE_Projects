// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WXWidgetController.h"

void UWXWidgetController::SetWidgetCtrlParams(const FWidgetContrllerParam& wcParams)
{
	mPlayerController = wcParams.mPC;
	mPlayerState= wcParams.mPS; 
	mAbilitySystemComponent=wcParams.mASC;
	mAttitudeSet = wcParams.mAS;
}
