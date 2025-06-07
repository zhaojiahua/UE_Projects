#include "AbilitySystems/WXAbilitySystemComponent.h"

void UWXAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UWXAbilitySystemComponent::EffectApplied);
}

void UWXAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* abilitySystemComponent, const FGameplayEffectSpec& effectSpec, FActiveGameplayEffectHandle activeEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 4.f, FColor::Red, FString("Effect Applied"));
}
