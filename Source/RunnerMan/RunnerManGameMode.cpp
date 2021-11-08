// Copyright Epic Games, Inc. All Rights Reserved.

#include "RunnerManGameMode.h"
#include "RunnerManCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARunnerManGameMode::ARunnerManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
