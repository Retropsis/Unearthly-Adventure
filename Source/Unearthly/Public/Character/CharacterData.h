#pragma once

#include "CoreMinimal.h"
#include "CharacterData.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName="Unequipped"),
	ECS_Equipped UMETA(DisplayName="Equipped")
};

UENUM(BlueprintType)
enum class EActionState : uint8
{
	EAS_Unoccupied UMETA(DisplayName="Unoccupied"),
	EAS_Attacking UMETA(DisplayName="Attacking")
};
