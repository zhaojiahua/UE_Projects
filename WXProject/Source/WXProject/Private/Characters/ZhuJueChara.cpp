// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ZhuJueChara.h"
#include "GamePlayers/WXPlayerState.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
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
	attributeSet = wxPalyerState->GetAttributeSet();//ͬ�����ǳ��е�attributeSetҲ��PlayerState�ĵ�

}
