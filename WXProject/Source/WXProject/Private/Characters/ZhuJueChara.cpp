// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ZhuJueChara.h"
#include "GamePlayers/WXPlayerState.h"
#include "AbilitySystems/WXAbilitySystemComponent.h"
#include <AbilitySystemComponent.h>
#include "UI/WXHUD.h"
void AZhuJueChara::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);
	InitAbilityActorInfo();//��ʼ��������
}
void AZhuJueChara::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();//���еĿͻ��˶���ʼ��
}

void AZhuJueChara::InitAbilityActorInfo()
{
	AWXPlayerState* wxPalyerState = GetPlayerState<AWXPlayerState>();
	check(wxPalyerState);
	abilitySystemComponent = wxPalyerState->GetAbilitySystemComponent();//���ǵ�AbilitySystemComponent�ǳ���PlayerState�ĵ�;
	abilitySystemComponent->InitAbilityActorInfo(wxPalyerState, this);
	Cast<UWXAbilitySystemComponent>(abilitySystemComponent)->AbilityActorInfoSet();//˳������һ��ASC��Effect�㲥����
	attributeSet = wxPalyerState->GetAttributeSet();//ͬ�����ǳ��е�attributeSetҲ��PlayerState�ĵ�

	//˳���HUD����Ĵ�Ԫ�ظ���ʼ����
	if (APlayerController* playerController = GetController<APlayerController>()) {
		if (AWXHUD* wxHUD = playerController->GetHUD<AWXHUD>()) {
			wxHUD->InitOverlayHUD(playerController, wxPalyerState, abilitySystemComponent, attributeSet);
		}
	}
}
