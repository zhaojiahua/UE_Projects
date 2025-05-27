// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WXUserWidget.generated.h"


UCLASS()
class WXPROJECT_API UWXUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* inwc);//从HUD那里获取widgetController

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject>widgetController;


	UFUNCTION(BlueprintNativeEvent)
	void WidgetControllerSet();//获取widgetController之后根据其数据在蓝图中实现widget界面的变化
};
