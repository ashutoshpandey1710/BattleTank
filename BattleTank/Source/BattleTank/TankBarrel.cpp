// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::ElevateBarrel(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = RelativeSpeed * this->MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = this->RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation = FMath::Clamp<float>(RawNewRotation, this->MinElevation, this->MaxElevation);
	
	this->SetRelativeRotation(FRotator(Elevation, 0, 0));
}