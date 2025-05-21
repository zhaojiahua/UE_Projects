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
	virtual void PossessedBy(AController* newController) override;//�ڿ�������ʼ���ƽ�ɫ��ʱ���ʼ��������
	virtual void OnRep_PlayerState() override;//�����ų�ʼ�����еĿͻ���(ȷ���ͻ�����PlayerState)
protected:
	//��ʼ��ASC���(���ǵ�ASC�����PlayerState����)
	void InitAbilityActorInfo();
};
