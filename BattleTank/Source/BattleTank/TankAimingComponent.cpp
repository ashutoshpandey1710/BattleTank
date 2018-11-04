// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet) {
	this->Barrel = BarrelToSet;
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector Location, float LaunchSpeed) {

	AActor* Owner = this->GetOwner();
	if (!Owner) {
		UE_LOG(LogTemp, Error, TEXT("Could not find owner of aiming component."));
	}
	else {
		auto BarrelLocation = this->Barrel->GetSocketLocation(FName("Projectile"));

		FVector LaunchVelocity(0.0);
		if (!this->Barrel) { 
			UE_LOG(LogTemp, Error, TEXT("Could not find owner of barrel.")); 
		}
		if (UGameplayStatics::SuggestProjectileVelocity(this,
			LaunchVelocity, BarrelLocation, Location, LaunchSpeed)) {
			UE_LOG(LogTemp, Warning, TEXT("Firing at %s from %s"), *(LaunchVelocity.ToString()), *(BarrelLocation.ToString()));
		}

		/*UE_LOG(LogTemp, Warning, TEXT("Firing at %f from %s"), LaunchSpeed, *(BarrelLocation.ToString()));*/
	}
}

