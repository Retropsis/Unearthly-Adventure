// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterData.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCharacterAnimInstance;
class AWorldItem;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UNEARTHLY_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//~ Action Mappings
	void Equip();
	void Attack();
	bool CanAttack();
	//~ Action Mappings

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	EActionState ActionState = EActionState::EAS_Unoccupied;
	
	UPROPERTY(VisibleInstanceOnly)
	TObjectPtr<AWorldItem> OverlappingItem;

	TObjectPtr<UCharacterAnimInstance> CharacterAnimInstance;
	
public:
	FORCEINLINE void SetOverlappingItem(AWorldItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	UFUNCTION(BlueprintCallable) void SetActionState(const EActionState NewState) { ActionState = NewState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
