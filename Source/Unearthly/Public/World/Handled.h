// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "World/WorldItem.h"
#include "Handled.generated.h"

/**
 * 
 */
UCLASS()
class UNEARTHLY_API AHandled : public AWorldItem
{
	GENERATED_BODY()

public:
	void Equip(USceneComponent* InParent, FName InSocketName);

protected:
	virtual void OnBeginOverlap(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnEndOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
