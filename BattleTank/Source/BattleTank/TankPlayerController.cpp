// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

/// Get world location of linetrace through crosshair. True if hits landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	// Set the crosshair locatoin.
	// Deproject the screen position of the crosshair to a world direction.
	// Line trace along that direction and see what we hit.
	
	OutHitLocation = FVector(1.0);
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation(this->CrosshairXLocation * ViewportSizeX, this->CrosshairYLocation * ViewportSizeY);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	

	return true;
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(this->GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	this->World = GetWorld();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!this->GetControlledTank()) { return; }

	// Get world location of linetrace through crosshair.
	// If it hits the landscape
		// Tell controlled tank to aim at that location.

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		// TODO Tell controlled tank to aim at this location.
		this->GetControlledTank()->AimAt(HitLocation);
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

bool ATankPlayerController::GetLookDirection(
	FVector2D CrosshairScreenLocation, 
	FVector & LookDirection) const	
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		CrosshairScreenLocation.X, 
		CrosshairScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const {
	if (this->World) {
		FVector TraceStart = PlayerCameraManager->GetCameraLocation();
		FVector TraceEnd = TraceStart + LookDirection * this->LineTraceRange;
		
		FHitResult HitResult;
		bool DidItHit = this->World->LineTraceSingleByChannel(
			HitResult,
			TraceStart,
			TraceEnd,
			ECC_Visibility);
		if (DidItHit) {
			OutHitLocation.X = HitResult.ImpactPoint.X;
			OutHitLocation.Y = HitResult.ImpactPoint.Y;
			OutHitLocation.Z = HitResult.ImpactPoint.Z;
		}

		DrawDebugLine(this->World, TraceStart, TraceEnd, FColor(0xcc2626), false, -1.0, 0, 2.0f);
		return DidItHit;
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("GetLookVectorHitLocation: Could not initialize World Object."));
		return false;
	}
}

