// @Retropsis 2024

#include "World/Breakable/BreakableActor.h"

#include "Components/CapsuleComponent.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "World/WorldLoot.h"

ABreakableActor::ABreakableActor()
{
	PrimaryActorTick.bCanEverTick = false;
	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	SetRootComponent(GeometryCollection);
	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GeometryCollection->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(GetRootComponent());
	CapsuleComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
}

void ABreakableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABreakableActor::GetHit_Implementation(const FVector& ImpactPoint)
{
	if(bBroken) return;
	bBroken = true;
	GeometryCollection->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	Location.Z += 75.f;
	int32 RandomLootIndex = FMath::RandRange(0, LootClasses.Num()-1);
	if (World && LootClasses.Num() > 0)
	{
		World->SpawnActor<AWorldLoot>(LootClasses[RandomLootIndex], Location, GetActorRotation());
	}
}
