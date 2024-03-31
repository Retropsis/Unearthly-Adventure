// @Retropsis 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttribute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNEARTHLY_API UCharacterAttribute : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterAttribute();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Character|Attributes")
	float Health;
	
	UPROPERTY(EditAnywhere, Category="Character|Attributes")
	float MaxHealth;

		
};
