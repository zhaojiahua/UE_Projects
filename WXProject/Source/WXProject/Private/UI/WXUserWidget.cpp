// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WXUserWidget.h"

void UWXUserWidget::SetWidgetController(UObject* inwc)
{
	widgetController = inwc;
	WidgetControllerSet();
}
