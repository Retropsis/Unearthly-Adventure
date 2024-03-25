// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "CharacterData.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class UNEARTHLY_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//~ Action Mapping Montages
	//~ Attack
	void PlayAttackMontage(const FName SectionName);
	UFUNCTION(BlueprintCallable) void AttackEnd();

	UPROPERTY(EditDefaultsOnly, Category="Character|Montages")
	TObjectPtr<UAnimMontage> AttackMontage;
	
	//~ Equip
	void PlayEquipMontage(const FName SectionName);
	
	UPROPERTY(EditDefaultsOnly, Category="Character|Montages")
	TObjectPtr<UAnimMontage> EquipMontage;
	
	UFUNCTION(BlueprintCallable) void SheatheHandled();
	UFUNCTION(BlueprintCallable) void DrawHandled();
	UFUNCTION(BlueprintCallable) void EquipEnd();
	//~ Action Mapping Montages

	UFUNCTION(BlueprintCallable) void SetHandledCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);
	
	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	TObjectPtr<APlayerCharacter> PlayerCharacter;

	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	float GroundSpeed = 0.f;

	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	bool bAirborne = false;

	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	bool bIsAccelerating = false;
	
	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	bool bIsCrouched = false;

	UPROPERTY(BlueprintReadOnly, Category="Character|Movement")
	ECharacterState CharacterState;
};
