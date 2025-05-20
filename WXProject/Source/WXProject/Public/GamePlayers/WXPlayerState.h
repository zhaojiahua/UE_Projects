// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GameplayAbilities/Public/AbilitySystemInterface.h"
#include "GameplayAbilities/Public/AttributeSet.h"
#include "WXPlayerState.generated.h"

UCLASS()
class WXPROJECT_API AWXPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AWXPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return attributeSet; }
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;
};
