// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSpawner.h"

#include "BaseLevel.h"
#include "Engine.h"
#include "Components/BoxComponent.h"

// Sets default values
ALevelSpawner::ALevelSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelSpawner::BeginPlay()
{
	Super::BeginPlay();

	CONSTEXPR bool isSpawn = true;

	CONSTEXPR bool canSpawn = false;

	SpawnLevel(isSpawn);

	SpawnLevel(canSpawn);
	SpawnLevel(canSpawn);
	SpawnLevel(canSpawn);
}

// Called every frame
void ALevelSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelSpawner::SpawnLevel(bool isFirstSpawn)
{
	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);

	SpawnRotation = FRotator(0.0f, 90.0f, 0.0f);

	if (!isFirstSpawn)
	{
		ABaseLevel* LastLevel = LevelList.Last();

		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	int32 minRandom = 1;
	int32 maxRandom = 10;

	randomLevel = FMath::RandRange(minRandom, maxRandom);

	ABaseLevel* NewLevel = nullptr;

	if (randomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level1, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 2)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level2, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 3)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level3, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level4, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level5, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 6)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level6, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 7)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level7, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 8)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level8, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 9)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level9, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (randomLevel == 10)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level10, SpawnLocation, SpawnRotation, SpawnInfo);
	}

	if (NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ALevelSpawner::OnOverlapBegin);
		}
	}

	LevelList.Add(NewLevel);

	if (LevelList.Num() > 5)
	{
		LevelList.RemoveAt(0);
	}
}

void ALevelSpawner::OnOverlapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 bodyIndex, bool isBFromSweep, const FHitResult& SweepResult)
{
	constexpr bool isSpawn = false;

	SpawnLevel(isSpawn); 
}

