// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterData.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class AHandled;
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
	//~ Action Mappings

	bool CanAttack();
	bool ShouldSheathe();
	bool ShouldDraw();
	
	void SheatheHandled();
	void DrawHandled();

	void SetHandledCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);
	
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
	
	UPROPERTY(VisibleInstanceOnly)
	TObjectPtr<AHandled> EquippedHandled;

	TObjectPtr<UCharacterAnimInstance> CharacterAnimInstance;
	
public:
	FORCEINLINE void SetOverlappingItem(AWorldItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	UFUNCTION(BlueprintCallable) void SetActionState(const EActionState NewState) { ActionState = NewState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
