// @Retropsis 2024

#include "World/Handled.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Interaction/HitInterface.h"
#include "Kismet/GameplayStatics.h"

AHandled::AHandled()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(GetRootComponent());
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	BoxTraceStart = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceStart"));
	BoxTraceStart->SetupAttachment(GetRootComponent());
	BoxTraceEnd = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceEnd"));
	BoxTraceEnd->SetupAttachment(GetRootComponent());

}

void AHandled::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AHandled::OnBoxBeginOverlap);
}

void AHandled::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AHandled::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AHandled::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FVector Start = BoxTraceStart->GetComponentLocation();
	const FVector End = BoxTraceEnd->GetComponentLocation();
	IgnoreActors.Add(this);
	FHitResult BoxHit;
	
	UKismetSystemLibrary::BoxTraceSingle(this, Start, End, FVector(5.f, 5.f, 5.f),
		BoxTraceStart->GetComponentRotation(), TraceTypeQuery1, false,
		IgnoreActors, EDrawDebugTrace::ForDuration, BoxHit, true);

	if (BoxHit.GetActor())
	{
		if (const IHitInterface* HitInterface = Cast<IHitInterface>(BoxHit.GetActor()))
		{
			HitInterface->Execute_GetHit(BoxHit.GetActor(), BoxHit.ImpactPoint);
		}
		IgnoreActors.AddUnique(BoxHit.GetActor());
		CreateFields(BoxHit.ImpactPoint);
	}
}

void AHandled::Equip(USceneComponent* InParent, FName InSocketName)
{
	AttachHandledTo(InParent, InSocketName);
	ItemState = EItemState::EIS_Equipped;
	PlayPickupSound();
	OverlapSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AHandled::AttachHandledTo(USceneComponent* InParent, FName InSocketName)
{
	const FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	ItemMesh->AttachToComponent(InParent, TransformRules, InSocketName);
}
