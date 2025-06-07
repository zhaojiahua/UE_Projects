// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <AttributeSet.h>
#include <AbilitySystemComponent.h>
#include <GameplayEffectExtension.h>
#include "WXAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class ACharacter;
USTRUCT()
struct FEffectProperties //在GameplayEffect执行后存储所作用的信息包括Source和Target等
{
	GENERATED_BODY()
	FEffectProperties() {};
	
	FGameplayEffectContextHandle effectContextHandle;
	UPROPERTY()
	UAbilitySystemComponent* sourceASC = nullptr;
	UPROPERTY()
	AActor* sourceAvatarActor = nullptr;
	UPROPERTY()
	AController* sourceController = nullptr;
	UPROPERTY()
	ACharacter* sourceCharacter = nullptr;
	UPROPERTY()
	UAbilitySystemComponent* targetASC = nullptr;
	UPROPERTY()
	AActor* targetAvatarActor = nullptr;
	UPROPERTY()
	AController* targetController = nullptr;
	UPROPERTY()
	ACharacter* targetCharacter = nullptr;
};

UCLASS()
class WXPROJECT_API UWXAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UWXAttributeSet();
	//用于属性值的网络同步,定义哪些属性需要被复制
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_HP,category="VitalAttribute")
	FGameplayAttributeData HP;//实时血量
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, HP);

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MaxHP, category = "VitalAttribute")
	FGameplayAttributeData MaxHP;//最大血量
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MaxHP);

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MP, category = "VitalAttribute")
	FGameplayAttributeData MP;//实时蓝量
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MP);

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MaxMP, category = "VitalAttribute")
	FGameplayAttributeData MaxMP;//最大蓝量
	ATTRIBUTE_ACCESSORS(UWXAttributeSet, MaxMP);


	UFUNCTION()
	void OnRep_HP(const FGameplayAttributeData oldHP)const;//血量发生变化调用此函数
	UFUNCTION()
	void OnRep_MP(const FGameplayAttributeData oldMP)const;//蓝量发生变化调用此函数
	UFUNCTION()
	void OnRep_MaxHP(const FGameplayAttributeData oldMaxHP)const;
	UFUNCTION()
	void OnRep_MaxMP(const FGameplayAttributeData oldMaxMP)const;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)override;
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& data, FEffectProperties props);
};
