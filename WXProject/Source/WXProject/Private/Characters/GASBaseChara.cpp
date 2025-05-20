// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GASBaseChara.h"

// Sets default values
AGASBaseChara::AGASBaseChara()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGASBaseChara::BeginPlay()
{
	Super::BeginPlay();
	
}
UAbilitySystemComponent* AGASBaseChara::GetAbilitySystemComponent() const
{
	return abilitySystemComponent;
}