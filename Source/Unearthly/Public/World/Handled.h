// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "World/WorldItem.h"
#include "Handled.generated.h"

class UBoxComponent;
/**
 * 
 */
UCLASS()
class UNEARTHLY_API AHandled : public AWorldItem
{
	GENERATED_BODY()

public:
	AHandled();
	void Equip(USceneComponent* InParent, FName InSocketName);
	void AttachHandledTo(USceneComponent* InParent, FName InSocketName);

	TArray<TObjectPtr<AActor>> IgnoreActors;

protected:
	virtual void BeginPlay() override;
	
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
	/*
	 * Collision Box
	 */
	UPROPERTY(VisibleAnywhere, Category="Weapon|Collision")
	TObjectPtr<UBoxComponent> CollisionBox;
	
	UPROPERTY(VisibleAnywhere, Category="Weapon|Collision")
	TObjectPtr<USceneComponent> BoxTraceStart;
	
	UPROPERTY(VisibleAnywhere, Category="Weapon|Collision")
	TObjectPtr<USceneComponent> BoxTraceEnd;
	
	UFUNCTION()
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*
	 * Destruction
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);

public:
	FORCEINLINE UBoxComponent* GetCollisionBox() const { return CollisionBox; }
};
