// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevel.h"

#include "Components/BoxComponent.h"

// Sets default values
ABaseLevel::ABaseLevel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseLevel::BeginPlay()
{
	Super::BeginPlay();

	if (Trigger != nullptr)
		Trigger->bHiddenInGame = true;
}

// Called every frame
void ABaseLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLevel::GetTrigger()
{
	return Trigger;
}

UBoxComponent* ABaseLevel::GetSpawnLocation()
{
	return SpawnLocation;
}

