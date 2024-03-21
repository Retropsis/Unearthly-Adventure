// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnearthlyGameMode.h"
#include "UnearthlyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnearthlyGameMode::AUnearthlyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
