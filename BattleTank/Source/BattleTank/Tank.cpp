// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	this->TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//this->TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}

void ATank::AimAt(FVector HitLocation) {
	this->TankAimingComponent->AimAt(HitLocation, this->LaunchSpeed);
	
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	this->TankAimingComponent->SetBarrelReference(BarrelToSet);
	this->Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet) {
	this->TankAimingComponent->SetTurretReference(TurretToSet);
}	

void ATank::Fire() {
	bool isReloaded = (FPlatformTime::Seconds() - this->LastFireTime) > this->ReloadTimeInSeconds;

	if (this->Barrel && isReloaded) {

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			this->Projectile,
			this->Barrel->GetSocketLocation(FName("Projectile")),
			this->Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(this->LaunchSpeed);

		this->LastFireTime = FPlatformTime::Seconds();
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

