// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interaction/HitInterface.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class UNEARTHLY_API AEnemy : public ABaseCharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();

	//~ Hit Interface
	virtual void GetHit(const FVector& ImpactPoint) override;
	//~ Hit Interface

private:
	//~ Montages
	void PlayHitReactMontage(const FName& SectionName);
	
	UPROPERTY(EditDefaultsOnly, Category="Character|Montages")
	TObjectPtr<UAnimMontage> HitReactMontage;
};
