#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EItemState : uint8
{
	EIS_Idling UMETA(DisplayName="Idling"),
	EIS_Hovering UMETA(DisplayName="Hovering"),
	EIS_Equipped UMETA(DisplayName="Equipped")
};
