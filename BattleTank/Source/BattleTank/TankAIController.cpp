// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}



void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	ATank* ControlledTank = Cast<ATank>(this->GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ControlledTank) { return; }
	if (!PlayerTank) { return; }

	FVector HitLocatoin = PlayerTank->GetActorLocation();
	
	ControlledTank->AimAt(HitLocatoin);
	ControlledTank->Fire(); //TODO Don't fire every frame.
}

