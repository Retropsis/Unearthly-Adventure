// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/HitInterface.h"
#include "BreakableActor.generated.h"

class UCapsuleComponent;
class AWorldLoot;

UCLASS()
class UNEARTHLY_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakableActor();
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World|SFX")
	TObjectPtr<USoundBase> BreakingSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World|Collision")
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGeometryCollectionComponent> GeometryCollection;

	UPROPERTY(EditAnywhere, Category="World|Loot")
	TArray<TSubclassOf<AWorldLoot>> LootClasses;

	bool bBroken = false;
};
