// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayers/WXPlayerState.h"
#include "GameFramework/Actor.h"
#include "AbilitySystems/WXAbilitySystemComponent.h"

AWXPlayerState::AWXPlayerState()
{
	NetUpdateFrequency = 100;

	abilitySystemComponent = CreateDefaultSubobject<UWXAbilitySystemComponent>("abilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	wxattributeSet = CreateDefaultSubobject<UWXAttributeSet>("wxattributeSet");

	//��������ͬ��ģʽ
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}
UAbilitySystemComponent* AWXPlayerState::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}