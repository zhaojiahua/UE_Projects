// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WXWidgetController.h"
#include "AbilitySystems/WXAttributeSet.h"
#include "GameplayAbilities/Public/GameplayEffectTypes.h"

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

void UWXWidgetController::BindCallbackToDependencies()
{
	const UWXAttributeSet* wxas = CastChecked<UWXAttributeSet>(mAttitudeSet);
	mAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(wxas->GetHPAttribute()).AddUObject(this,&UWXWidgetController::HPChange);
	mAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(wxas->GetMPAttribute()).AddUObject(this,&UWXWidgetController::MPChange);
	mAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(wxas->GetMaxHPAttribute()).AddUObject(this,&UWXWidgetController::MaxHPChange);
	mAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(wxas->GetMaxMPAttribute()).AddUObject(this,&UWXWidgetController::MaxMPChange);
}

void UWXWidgetController::HPChange(const FOnAttributeChangeData& changeData) const
{
	OnHpChangeSignature.Broadcast(changeData.NewValue);
}

void UWXWidgetController::MaxHPChange(const FOnAttributeChangeData& changeData) const
{
	OnMaxHpChangeSignature.Broadcast(changeData.NewValue);
}

void UWXWidgetController::MPChange(const FOnAttributeChangeData& changeData) const
{
	OnMpChangeSignature.Broadcast(changeData.NewValue);
}

void UWXWidgetController::MaxMPChange(const FOnAttributeChangeData& changeData) const
{
	OnMaxMpChangeSignature.Broadcast(changeData.NewValue);
}
