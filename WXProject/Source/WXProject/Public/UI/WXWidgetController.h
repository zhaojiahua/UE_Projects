// 这是一个专门处理widget数据广播传输逻辑的类,它持有PlayerController PlayerState AbilitySystemComponent AttributeSet这四大元素,专门处理数据在这四大元素之间的传递和广播

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegates/Delegate.h"
#include "WXWidgetController.generated.h"

//动态多播委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHpChangeSignature, float, newHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHpChangeSignature, float, newMaxHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMpChangeSignature, float, newMP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxMpChangeSignature, float, newMaxMP);

class UAbilitySystemComponent;
class UAttributeSet;
class AAplayerState;
USTRUCT(BlueprintType)
struct FWidgetContrllerParam
{
	GENERATED_BODY()
	FWidgetContrllerParam() {}
	FWidgetContrllerParam(APlayerController* inpc,APlayerState* inps, UAbilitySystemComponent* inasc,UAttributeSet* inas):
		mPC(inpc), mPS(inps), mASC(inasc), mAS(inas)	{}
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerController> mPC = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> mPS = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> mASC = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> mAS = nullptr;

};

UCLASS(BlueprintType,Blueprintable)
class WXPROJECT_API UWXWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetCtrlParams(const FWidgetContrllerParam& wcParams);
	//广播初始值
	void BroadcastInitValue();
	UPROPERTY(BlueprintAssignable, Category = "GAS_Attributes")
	FOnHpChangeSignature OnHpChangeSignature;
	UPROPERTY(BlueprintAssignable, Category = "GAS_Attributes")
	FOnMaxHpChangeSignature OnMaxHpChangeSignature;
	UPROPERTY(BlueprintAssignable, Category = "GAS_Attributes")
	FOnMpChangeSignature OnMpChangeSignature;
	UPROPERTY(BlueprintAssignable, Category = "GAS_Attributes")
	FOnMaxMpChangeSignature OnMaxMpChangeSignature;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> mPlayerController= nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> mPlayerState = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> mAbilitySystemComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> mAttitudeSet = nullptr;

};
