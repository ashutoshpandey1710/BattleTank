// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

/// Get world location of linetrace through crosshair. True if hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	OutHitLocation = FVector(1.0);
	return true;
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(this->GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!this->GetControlledTank()) { return; }

	// Get world location of linetrace through crosshair.
	// If it hits the landscape
		// Tell controlled tank to aim at that location.

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		// TODO Tell controlled tank to aim at this location.
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

