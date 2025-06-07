// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameplayEffectTypes.h>
#include "WXEffectActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy:uint8 {
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};
UENUM(BlueprintType)
enum class EEffectRemovalPolicy:uint8{
	RemoveOnEndOverlap,
	DoNotRemove
};
UENUM(BlueprintType)
enum class GameplayEffectClassType :uint8 {
	Instant,
	Duration,
	Infinite
};
UCLASS()
class WXPROJECT_API AWXEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWXEffectActor();

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlap(AActor* targetActor);
	UFUNCTION(BlueprintCallable)
	virtual void OnEndOverlap(AActor* targetActor);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	float effectLevel = 1.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	TSubclassOf<UGameplayEffect> instantEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	TSubclassOf<UGameplayEffect> durationEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	TSubclassOf<UGameplayEffect> infiniteEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	EEffectApplicationPolicy instantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	EEffectApplicationPolicy durationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	EEffectApplicationPolicy infiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ApplyEffect")
	EEffectRemovalPolicy infiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;
	
	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> activeEffectHandles;
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> sphereCollision;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh;

};
