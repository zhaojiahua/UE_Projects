// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyChara.h"
#include "AbilitySystems/WXAbilitySystemComponent.h"
#include <AttributeSet.h>
#include <AbilitySystemComponent.h>

AEnemyChara::AEnemyChara()
{
	abilitySystemComponent = CreateDefaultSubobject<UWXAbilitySystemComponent>("abilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	attributeSet = CreateDefaultSubobject<UAttributeSet>("attributeSet");
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AEnemyChara::InitAbilityActorInfo()
{
	check(abilitySystemComponent);
	abilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UWXAbilitySystemComponent>(abilitySystemComponent)->AbilityActorInfoSet();//顺便设置一下ASC的Effect广播函数
}