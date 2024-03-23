// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

class APlayerCharacter;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class UNEARTHLY_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<APlayerCharacter> PlayerCharacter;
	
	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputMappingContext> CharacterContext;

	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> HandleAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> AttackAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> RollAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Chatacter|Input")
	TObjectPtr<UInputAction> LockAction;
	
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump();
	void HandleButtonPressed();
	void AttackButtonPressed();
	void RollButtonPressed();
	void LockButtonPressed();
};
