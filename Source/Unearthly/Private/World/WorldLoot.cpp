// @Retropsis 2024

#include "World/WorldLoot.h"
#include "Kismet/GameplayStatics.h"
#include "Player/PlayerCharacter.h"

void AWorldLoot::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor))
	{
		if(IsValid(PickupSound)) UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		Destroy();
	}
}
