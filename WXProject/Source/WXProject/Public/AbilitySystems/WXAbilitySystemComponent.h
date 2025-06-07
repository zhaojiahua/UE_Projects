#pragma once

#include "CoreMinimal.h"
#include <AbilitySystemComponent.h>
#include "WXAbilitySystemComponent.generated.h"

UCLASS()
class WXPROJECT_API UWXAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	//�󶨹㲥����
	void AbilityActorInfoSet();
protected:
	void EffectApplied(UAbilitySystemComponent* abilitySystemComponent, const FGameplayEffectSpec& effectSpec, FActiveGameplayEffectHandle activeEffectHandle);
};
