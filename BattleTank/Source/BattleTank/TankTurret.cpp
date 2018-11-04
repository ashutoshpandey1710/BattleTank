// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::RotateTurret(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	float AzimuthChange = RelativeSpeed * this->MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	float NewAzimuth = this->RelativeRotation.Yaw + AzimuthChange;
	this->SetRelativeRotation(FRotator(0.0f, NewAzimuth, 0.0f));
}
