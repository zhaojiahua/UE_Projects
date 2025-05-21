// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GASBaseChara.h"
#include "ZhuJueChara.generated.h"

UCLASS()
class WXPROJECT_API AZhuJueChara : public AGASBaseChara
{
	GENERATED_BODY()

public:
	virtual void PossessedBy(AController* newController) override;//在控制器开始控制角色的时候初始化服务器
	virtual void OnRep_PlayerState() override;//紧接着初始化所有的客户端(确保客户端有PlayerState)
protected:
	//初始化ASC组件(主角的ASC组件在PlayerState上面)
	void InitAbilityActorInfo();
};
