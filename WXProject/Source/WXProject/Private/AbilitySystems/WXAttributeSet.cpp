// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystems/WXAttributeSet.h"
#include "GameFramework/Character.h"
#include "UObject/CoreNet.h"
#include "Net/UnrealNetwork.h"
#include <AbilitySystemBlueprintLibrary.h>

UWXAttributeSet::UWXAttributeSet()
{
	HP = 50.f;
	MaxHP = 100.f;
	MP = 50.f;
	MaxMP = 200.f; 
}

void UWXAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//对于HP和MP,客户端无条件的一直复制服务端(把要同步的属性通过这个宏添加到同步列表)
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, HP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MaxHP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MaxMP, COND_None, REPNOTIFY_Always);
}
void UWXAttributeSet::OnRep_HP(const FGameplayAttributeData oldHP) const
{
	//使用默认的游戏玩法属性系统更新通知行为
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWXAttributeSet, HP, oldHP);
}

void UWXAttributeSet::OnRep_MP(const FGameplayAttributeData oldMP) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWXAttributeSet, MP, oldMP);
}

void UWXAttributeSet::OnRep_MaxHP(const FGameplayAttributeData oldMaxHP) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWXAttributeSet, MaxHP, oldMaxHP);
}

void UWXAttributeSet::OnRep_MaxMP(const FGameplayAttributeData oldMaxMP) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UWXAttributeSet, MaxMP, oldMaxMP);
}
void UWXAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHPAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHP());
	}
	if (Attribute == GetMPAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMP());
	}
}
void UWXAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FEffectProperties props;
	SetEffectProperties(Data, props);
}

void UWXAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& data, FEffectProperties props)
{
	props.effectContextHandle = data.EffectSpec.GetContext();
	//设置source
	props.sourceASC = props.effectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
	if (IsValid(props.sourceASC) && props.sourceASC->AbilityActorInfo.IsValid() && props.sourceASC->AbilityActorInfo->AvatarActor.IsValid()) {
		props.sourceAvatarActor = props.sourceASC->AbilityActorInfo->AvatarActor.Get();
		props.sourceController = props.sourceASC->AbilityActorInfo->PlayerController.Get();
		if (props.sourceController == nullptr && props.sourceAvatarActor != nullptr) {
			if (const APawn* pawn = Cast<APawn>(props.sourceAvatarActor))
				props.sourceController = pawn->GetController();
		}
		if (props.sourceController)
			props.sourceCharacter = Cast<ACharacter>(props.sourceController->GetPawn());
	}
	//设置target
	if (data.Target.AbilityActorInfo.IsValid() && data.Target.AbilityActorInfo->AvatarActor.IsValid()) {
		props.targetAvatarActor = data.Target.AbilityActorInfo->AvatarActor.Get();
		props.targetController = data.Target.AbilityActorInfo->PlayerController.Get();
		props.targetCharacter = Cast<ACharacter>(props.targetAvatarActor);
		props.targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(props.targetAvatarActor);
	}
}
