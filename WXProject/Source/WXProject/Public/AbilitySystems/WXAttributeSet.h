// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
#include "WXAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class WXPROJECT_API UWXAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UWXAttributeSet();
	//��������ֵ������ͬ��,������Щ������Ҫ������
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HP,category="VitalAttribute")
	FGameplayAttributeData HP;//ʵʱѪ��
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, HP);
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHP, category = "VitalAttribute")
	FGameplayAttributeData MaxHP;//���Ѫ��
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MaxHP);
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MP, category = "VitalAttribute")
	FGameplayAttributeData MP;//ʵʱ����
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MP);
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMP, category = "VitalAttribute")
	FGameplayAttributeData MaxMP;//�������
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MaxMP);

	UFUNCTION()
	void OnRep_HP(const FGameplayAttributeData oldHP)const;//Ѫ�������仯���ô˺���
	UFUNCTION()
	void OnRep_MP(const FGameplayAttributeData oldMP)const;//���������仯���ô˺���
	UFUNCTION()
	void OnRep_MaxHP(const FGameplayAttributeData oldMaxHP)const;
	UFUNCTION()
	void OnRep_MaxMP(const FGameplayAttributeData oldMaxMP)const;
};
