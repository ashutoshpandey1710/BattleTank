// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(this->GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto AIPosessedTank = this->GetControlledTank();

	if (AIPosessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Posessed Tank: %s"), *(AIPosessedTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController: No tank found!"));
	}
}
