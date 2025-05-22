// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WXEffectActor.h"
#include "Components/SphereComponent.h"
#include "GameplayAbilities/Public/AbilitySystemInterface.h"
#include "AbilitySystems/WXAttributeSet.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"


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

void AWXEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ascInterface = Cast<IAbilitySystemInterface>(OtherActor)){
		const UWXAttributeSet* wxattributeSet = Cast<UWXAttributeSet>(ascInterface->GetAbilitySystemComponent()->GetAttributeSet(UWXAttributeSet::StaticClass()));
		//下面是用于测试后面要改过来
		UWXAttributeSet* testAttributeSet = const_cast<UWXAttributeSet*>(wxattributeSet);
		testAttributeSet->SetHP(wxattributeSet->GetHP() + 25.0f);
		Destroy();
	}
}

// Called when the game starts or when spawned
void AWXEffectActor::BeginPlay()
{
	Super::BeginPlay();
	sphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AWXEffectActor::OnOverlap);
}


