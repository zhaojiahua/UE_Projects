// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include <AbilitySystemInterface.h>
#include <AttributeSet.h>
#include "AbilitySystems/WXAttributeSet.h"
#include "WXPlayerState.generated.h"

class UWXAbilitySystemComponent;
UCLASS()
class WXPROJECT_API AWXPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AWXPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return wxattributeSet; }
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> wxattributeSet;
};
