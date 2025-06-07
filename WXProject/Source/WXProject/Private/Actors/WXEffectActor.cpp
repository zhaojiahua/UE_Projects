// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/WXEffectActor.h"
#include "AbilitySystems/WXAttributeSet.h"
#include "Components/SphereComponent.h"
#include <AbilitySystemInterface.h>
#include <AbilitySystemComponent.h>
#include <GameplayEffect.h>
#include <AbilitySystemBlueprintLibrary.h>


// Sets default values
AWXEffectActor::AWXEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	AActor::SetRootComponent(mesh);

	sphereCollision = CreateDefaultSubobject<USphereComponent>("sphereCollision");
	sphereCollision->SetupAttachment(mesh);
}

void AWXEffectActor::OnOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(targetActor, instantEffectClass);
	}
	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(targetActor, durationEffectClass);
	}
	if (infiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(targetActor, infiniteEffectClass);
	}
}
void AWXEffectActor::OnEndOverlap(AActor* targetActor)
{
	if (instantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(targetActor, instantEffectClass);
	}
	if (durationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(targetActor, durationEffectClass);
	}
	if (infiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(targetActor, infiniteEffectClass);
	}
	UAbilitySystemComponent* targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
	if (!IsValid(targetASC))return;
	TArray<FActiveGameplayEffectHandle> handlesToRemove;
	for (auto handlePair : activeEffectHandles) {
		if (handlePair.Value == targetASC) {
			targetASC->RemoveActiveGameplayEffect(handlePair.Key);
			handlesToRemove.Add(handlePair.Key);
		}
	}
	for (auto handle : handlesToRemove) {
		activeEffectHandles.FindAndRemoveChecked(handle);
	}
}

// Called when the game starts or when spawned
void AWXEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AWXEffectActor::ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	UAbilitySystemComponent* targetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor);
	if (targetASC == nullptr)return;
	check(gameplayEffectClass);
	FGameplayEffectContextHandle effectContextHandle = targetASC->MakeEffectContext();
	effectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle effectSpecHandle = targetASC->MakeOutgoingSpec(gameplayEffectClass, effectLevel, effectContextHandle);
	FActiveGameplayEffectHandle activeEffectHandle=targetASC->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());
	if (effectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite) {
		if (infiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{activeEffectHandles.Add(activeEffectHandle, targetASC);}
	}
}


