// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "World/WorldItem.h"
#include "WorldLoot.generated.h"

/**
 * 
 */
UCLASS()
class UNEARTHLY_API AWorldLoot : public AWorldItem
{
	GENERATED_BODY()

protected:
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere, Category="WorldItem|Properties")
	int32 Gold;
};
