// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(this->GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	/*ATank* PosessedTank = this->GetControlledTank();

	if (PosessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Posessed Tank: %s"), *(PosessedTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("ATankPlayerController: No tank found!"));
	}*/
	
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!this->GetControlledTank()) { return; }

	// Get world location of linetrace through crosshair.
	// If it hits the landscape.


}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

