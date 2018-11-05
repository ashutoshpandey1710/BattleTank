// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Engine/World.h"


void UTankMovementComponent::IntendMoveForward(float Throw) {
	/*if (FGenericPlatformMath::Abs(Throw) > 0.0001) {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Intend move forward throw: %f"), Time, Throw);
	}*/
	if (!this->LeftTrack || !this->RightTrack) { return; }

	this->LeftTrack->SetThrottle(Throw);
	this->RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw) {

	if (!this->LeftTrack || !this->RightTrack) { return; }

	this->LeftTrack->SetThrottle(-1.0f * Throw);
	this->RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (!this->LeftTrack || !this->RightTrack) { return; }

	this->LeftTrack->SetThrottle(Throw);
	this->RightTrack->SetThrottle(-1.0f * Throw);
}

void UTankMovementComponent::Initialize(UTankTrack * LeftTrack, UTankTrack * RightTrack) {
	if (!LeftTrack || !RightTrack) { return; }

	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}
