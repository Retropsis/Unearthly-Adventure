// @Retropsis 2024

#include "Player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "World/Handled.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//~ Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	//~ Camera

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CharacterAnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::Equip()
{
	if(AHandled* OverlappingHandled = Cast<AHandled>(OverlappingItem))
	{
		OverlappingHandled->Equip(GetMesh(), FName("LeftHandSocket"));
		CharacterState = ECharacterState::ECS_Equipped;
	}
}

void APlayerCharacter::Attack()
{
	if(!CanAttack()) return;

	ActionState = EActionState::EAS_Attacking;
	
	const FName SectionName = FMath::RandRange(0, 1) == 0 ? FName("Attack1") : FName("Attack2");
	if(CharacterAnimInstance) CharacterAnimInstance->PlayAttackMontage(SectionName);
}

bool APlayerCharacter::CanAttack()
{
	return ActionState == EActionState::EAS_Unoccupied && CharacterState == ECharacterState::ECS_Equipped;
}

