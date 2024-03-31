// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interaction/HitInterface.h"
#include "Enemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class UNEARTHLY_API AEnemy : public ABaseCharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	void DirectionalHitReact(const FVector& ImpactPoint);

	//~ Hit Interface
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	//~ Hit Interface

	UPROPERTY(EditAnywhere, Category="Character|Sound")
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere, Category="Character|VFX")
	TObjectPtr<UParticleSystem> ImpactEffect;

private:
	//~ Montages
	void PlayHitReactMontage(const FName& SectionName);
	
	UPROPERTY(EditDefaultsOnly, Category="Character|Montages")
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UWidgetComponent> HealthBarComponent;
};
