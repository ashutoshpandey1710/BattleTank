// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 is max downward movement and 1 is max upward movement.
	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 5.0f; //Sensible default.

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevation = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevation = 40.0f;
};
