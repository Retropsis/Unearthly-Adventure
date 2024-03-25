// @Retropsis 2024

#include "Player/PlayerCharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/PlayerCharacter.h"

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Jump);
	EnhancedInputComponent->BindAction(HandleAction, ETriggerEvent::Started, this, &APlayerCharacterController::HandleButtonPressed);
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &APlayerCharacterController::AttackButtonPressed);
	EnhancedInputComponent->BindAction(RollAction, ETriggerEvent::Started, this, &APlayerCharacterController::RollButtonPressed);
	EnhancedInputComponent->BindAction(LockAction, ETriggerEvent::Started, this, &APlayerCharacterController::LockButtonPressed);
}

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
	checkf(CharacterContext, TEXT("Missing CharacterMappingContext, check CharacterPlayerController"));
	if(UEnhancedInputLocalPlayerSubsystem*  Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(CharacterContext, 0);
	}
	PlayerCharacter = Cast<APlayerCharacter>(GetCharacter());
}

void APlayerCharacterController::Move(const FInputActionValue& InputActionValue)
{
	// TODO: Make Additive Attacks instead of pinning
	if(PlayerCharacter->GetActionState() != EActionState::EAS_Unoccupied) return;
	
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void APlayerCharacterController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APlayerCharacterController::Jump()
{
	if (PlayerCharacter) PlayerCharacter->Jump();
}

void APlayerCharacterController::HandleButtonPressed()
{
	if (PlayerCharacter) PlayerCharacter->Equip();
}

void APlayerCharacterController::AttackButtonPressed()
{
	if (PlayerCharacter) PlayerCharacter->Attack();
}

void APlayerCharacterController::RollButtonPressed()
{
}

void APlayerCharacterController::LockButtonPressed()
{
}
