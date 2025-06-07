#pragma once

#include "CoreMinimal.h"
#include <AbilitySystemComponent.h>
#include "WXAbilitySystemComponent.generated.h"

UCLASS()
class WXPROJECT_API UWXAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	//°ó¶¨¹ã²¥º¯Êý
	void AbilityActorInfoSet();
protected:
	void EffectApplied(UAbilitySystemComponent* abilitySystemComponent, const FGameplayEffectSpec& effectSpec, FActiveGameplayEffectHandle activeEffectHandle);
};
