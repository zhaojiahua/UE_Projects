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
	void SetWidgetController(UObject* inwc);//��HUD�����ȡwidgetController

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject>widgetController;


	UFUNCTION(BlueprintNativeEvent)
	void WidgetControllerSet();//��ȡwidgetController֮���������������ͼ��ʵ��widget����ı仯
};
