// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector Location, float LaunchSpeed) {

	AActor* Owner = this->GetOwner();
	if (!Owner) {
		UE_LOG(LogTemp, Error, TEXT("Could not find owner of aiming component."));
		return;
	}
	else {
		auto BarrelLocation = this->Barrel->GetSocketLocation(FName("Projectile"));

		FVector LaunchVelocity(0.0);
		if (!this->Barrel) { 
			UE_LOG(LogTemp, Error, TEXT("Could not find owner of barrel."));
			return;
		}

		bool bHaveFiringSolution = UGameplayStatics::SuggestProjectileVelocity(this,
			LaunchVelocity, BarrelLocation, Location, LaunchSpeed);
		
		if (bHaveFiringSolution) {

			auto AimDirection = LaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
			//MoveBarrel();
				// Set Turret Z rotation to the z rotation of the aim velocity unit vector
				// Set Barrel Y rotation to the y rotation of the aim velocity unit vector.
			//UE_LOG(LogTemp, Warning, TEXT("Firing at %s from %s"), *(AimDirection.ToString()), *(BarrelLocation.ToString()));
		}
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	auto BarrelRotator = this->Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;


	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *(AimAsRotator.ToString()));
}

