// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "WorldItemData.h"
#include "GameFramework/Actor.h"
#include "WorldItem.generated.h"

class USphereComponent;

UCLASS()
class UNEARTHLY_API AWorldItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AWorldItem();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> OverlapSphere;
	
	UPROPERTY(EditDefaultsOnly, Category="World|SFX")
	TObjectPtr<USoundBase> PickupSound;

protected:
	virtual void BeginPlay() override;
	virtual void PlayPickupSound();

	UFUNCTION()
	virtual void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	EItemState ItemState = EItemState::EIS_Idling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World|VFX")
	float Amplitude = 0.25f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="World|VFX")
	float TimeConstant = 5.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="World|VFX")
	float RunningTime = 0.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();
	
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename  T>
	T Avg(T First, T Second)
	{
		return  (First + Second) / 2;
	}
};
