// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(this->GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	this->World = GetWorld();

	if (!World) {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController::BeginPlay: Could not find reference to World object."));
		FGenericPlatformMisc::RequestExit(false);
	}

	auto PlayerTank = this->GetPlayerTank();
	auto AIPosessedTank = this->GetControlledTank();

	
	if (PlayerTank) {
		if (AIPosessedTank) {
			//UE_LOG(LogTemp, Warning, TEXT("ATankAIController for %s::BeginPlay: Player Tank: %s"),*(AIPosessedTank->GetName()), *(PlayerTank->GetName()));
			//AIPosessedTank->AimAt(HitLocatoin);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("ATankAIController::BeginPlay: Could not find current AI posessed tank."));
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController::BeginPlay: Could not find player tank."));
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	FVector HitLocatoin = this->GetPlayerTank()->GetActorLocation();
	this->GetControlledTank()->AimAt(HitLocatoin);
}

ATank * ATankAIController::GetPlayerTank() const {
	if (this->World) {
		return Cast<ATank>(this->World->GetFirstPlayerController()->GetPawn());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("ATankAIController::GetPlayerTank: Could not find reference to World object."));
		return nullptr;
	}
		
}
