// GAS抽象类,所有GAS角色都继承此类

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayAbilities/Public/AbilitySystemInterface.h"
#include "GameplayAbilities/Public/AttributeSet.h"
#include "GASBaseChara.generated.h"

UCLASS(Abstract) //抽象类不能实例化,只能通过子类实例化
class WXPROJECT_API AGASBaseChara : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGASBaseChara();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return attributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> abilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> attributeSet;
};
