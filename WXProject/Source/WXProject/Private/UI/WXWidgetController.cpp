// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WXWidgetController.h"
#include "AbilitySystems/WXAttributeSet.h"

void UWXWidgetController::SetWidgetCtrlParams(const FWidgetContrllerParam& wcParams)
{
	mPlayerController = wcParams.mPC;
	mPlayerState= wcParams.mPS; 
	mAbilitySystemComponent=wcParams.mASC;
	mAttitudeSet = wcParams.mAS;
}

void UWXWidgetController::BroadcastInitValue()
{
	const UWXAttributeSet* wxas = CastChecked<UWXAttributeSet>(mAttitudeSet);
	OnHpChangeSignature.Broadcast(wxas->GetHP());
	OnMaxHpChangeSignature.Broadcast(wxas->GetMaxHP());
	OnMpChangeSignature.Broadcast(wxas->GetMP());
	OnMaxMpChangeSignature.Broadcast(wxas->GetMaxMP());
}
