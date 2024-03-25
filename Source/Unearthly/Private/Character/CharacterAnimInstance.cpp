// @Retropsis 2024

#include "Character/CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/PlayerCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	// TODO: check lazy init
	if(PlayerCharacter == nullptr)
	{
		PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
	if(PlayerCharacter == nullptr) return;

	GroundSpeed = UKismetMathLibrary::VSizeXY(PlayerCharacter->GetVelocity());
	bAirborne = PlayerCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
	bIsCrouched = PlayerCharacter->bIsCrouched;
	CharacterState = PlayerCharacter->GetCharacterState();
}

void UCharacterAnimInstance::PlayAttackMontage(const FName SectionName)
{
	if (AttackMontage)
	{
		Montage_Play(AttackMontage);
		Montage_JumpToSection(SectionName);
	}
}

void UCharacterAnimInstance::AttackEnd()
{
	PlayerCharacter->SetActionState(EActionState::EAS_Unoccupied);
}

void UCharacterAnimInstance::PlayEquipMontage(const FName SectionName)
{
	if (EquipMontage)
	{
		Montage_Play(EquipMontage);
		Montage_JumpToSection(SectionName);
	}
}

void UCharacterAnimInstance::SheatheHandled()
{
	PlayerCharacter->SheatheHandled();
}

void UCharacterAnimInstance::DrawHandled()
{
	PlayerCharacter->DrawHandled();
}

void UCharacterAnimInstance::EquipEnd()
{
	PlayerCharacter->SetActionState(EActionState::EAS_Unoccupied);
}

void UCharacterAnimInstance::SetHandledCollisionEnabled(const ECollisionEnabled::Type CollisionEnabled)
{
	PlayerCharacter->SetHandledCollisionEnabled(CollisionEnabled);
}
