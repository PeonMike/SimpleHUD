// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleHUDGameMode.h"
#include "SimpleHUDCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleHUDGameMode::ASimpleHUDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
