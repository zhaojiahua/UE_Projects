// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayers/WXPlayerState.h"
#include "GameFramework/Actor.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"

AWXPlayerState::AWXPlayerState()
{
	NetUpdateFrequency = 100;

	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("abilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	attributeSet = CreateDefaultSubobject<UAttributeSet>("attributeSet");

	//设置属性同步模式
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}
UAbilitySystemComponent* AWXPlayerState::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}