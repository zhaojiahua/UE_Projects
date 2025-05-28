// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WXHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/WXWidgetController.h"
#include "UI/WXUserWidget.h"

UWXWidgetController* AWXHUD::GetOverlayWidgetController(const FWidgetContrllerParam& wctrlParams)
{
	if (overlayWidgetController == nullptr) {
		overlayWidgetController = NewObject<UWXWidgetController>(this, overlayWidgetControllerClass);
		overlayWidgetController->SetWidgetCtrlParams(wctrlParams);
		//获取到WidgetController的时候就立刻把广播函数绑定好
		overlayWidgetController->BindCallbackToDependencies();
	}
	return overlayWidgetController;
}

void AWXHUD::InitOverlayHUD(APlayerController* inpc, APlayerState* inps, UAbilitySystemComponent* inasc, UAttributeSet* inas)
{
	checkf(overlayWidgetClass, TEXT("overlayWidgetClass is null !"));
	checkf(overlayWidgetControllerClass, TEXT("overlayWidgetControllerClass is null !"));
	
	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), overlayWidgetClass);
	overlayWidget = Cast<UWXUserWidget>(widget);

	//四大元素赋值
	const FWidgetContrllerParam wcParams(inpc, inps, inasc, inas);
	UWXWidgetController* widgetCtrl = GetOverlayWidgetController(wcParams);
	overlayWidget->SetWidgetController(widgetCtrl);
	widgetCtrl->BroadcastInitValue();//广播初始值(一定要设置好WidgetController之后再广播)

	widget->AddToViewport();
}
