// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyChara.h"
#include "GameplayAbilities/Public/AttributeSet.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"

AEnemyChara::AEnemyChara()
{
	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("abilitySystemComponent");
	abilitySystemComponent->SetIsReplicated(true);
	attributeSet = CreateDefaultSubobject<UAttributeSet>("attributeSet");
	abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}
void AEnemyChara::BeginPlay()
{
	Super::BeginPlay();
	check(abilitySystemComponent);
	abilitySystemComponent->InitAbilityActorInfo(this, this);
}
