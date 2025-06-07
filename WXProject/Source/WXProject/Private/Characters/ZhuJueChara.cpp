// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ZhuJueChara.h"
#include "GamePlayers/WXPlayerState.h"
#include "AbilitySystems/WXAbilitySystemComponent.h"
#include <AbilitySystemComponent.h>
#include "UI/WXHUD.h"
void AZhuJueChara::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);
	InitAbilityActorInfo();//初始化服务器
}
void AZhuJueChara::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();//所有的客户端都初始化
}

void AZhuJueChara::InitAbilityActorInfo()
{
	AWXPlayerState* wxPalyerState = GetPlayerState<AWXPlayerState>();
	check(wxPalyerState);
	abilitySystemComponent = wxPalyerState->GetAbilitySystemComponent();//主角的AbilitySystemComponent是持有PlayerState的的;
	abilitySystemComponent->InitAbilityActorInfo(wxPalyerState, this);
	Cast<UWXAbilitySystemComponent>(abilitySystemComponent)->AbilityActorInfoSet();//顺便设置一下ASC的Effect广播函数
	attributeSet = wxPalyerState->GetAttributeSet();//同样主角持有的attributeSet也是PlayerState的的

	//顺便把HUD里的四大元素给初始化了
	if (APlayerController* playerController = GetController<APlayerController>()) {
		if (AWXHUD* wxHUD = playerController->GetHUD<AWXHUD>()) {
			wxHUD->InitOverlayHUD(playerController, wxPalyerState, abilitySystemComponent, attributeSet);
		}
	}
}
