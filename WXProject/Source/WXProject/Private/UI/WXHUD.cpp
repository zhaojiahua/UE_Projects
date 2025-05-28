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
		//��ȡ��WidgetController��ʱ������̰ѹ㲥�����󶨺�
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

	//�Ĵ�Ԫ�ظ�ֵ
	const FWidgetContrllerParam wcParams(inpc, inps, inasc, inas);
	UWXWidgetController* widgetCtrl = GetOverlayWidgetController(wcParams);
	overlayWidget->SetWidgetController(widgetCtrl);
	widgetCtrl->BroadcastInitValue();//�㲥��ʼֵ(һ��Ҫ���ú�WidgetController֮���ٹ㲥)

	widget->AddToViewport();
}
