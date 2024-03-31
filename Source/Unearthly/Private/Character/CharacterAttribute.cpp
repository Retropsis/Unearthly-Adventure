// @Retropsis 2024


#include "Character/CharacterAttribute.h"

UCharacterAttribute::UCharacterAttribute()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCharacterAttribute::BeginPlay()
{
	Super::BeginPlay();
}

void UCharacterAttribute::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

