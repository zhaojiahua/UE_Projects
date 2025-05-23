// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystems/WXAttributeSet.h"
#include "UObject/CoreNet.h"
#include "Net/UnrealNetwork.h"


UWXAttributeSet::UWXAttributeSet()
{
	//InitHP(100.0f);
	//InitMP(100.0f);
	//InitMaxHP(100.f);
	//InitMaxMP(100.f);
	HP = 100.f;
	MaxHP = 100.f;
	MP = 100.f;
	MaxMP = 100.f; 
}

void UWXAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//����HP��MP,�ͻ�����������һֱ���Ʒ����(��Ҫͬ��������ͨ���������ӵ�ͬ���б�)
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, HP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MaxHP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UWXAttributeSet, MaxMP, COND_None, REPNOTIFY_Always);
}
void UWXAttributeSet::OnRep_HP(const FGameplayAttributeData oldHP) const
{
	//ʹ��Ĭ�ϵ���Ϸ�淨����ϵͳ����֪ͨ��Ϊ
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
