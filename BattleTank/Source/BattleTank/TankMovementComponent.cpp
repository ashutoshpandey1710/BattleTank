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

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) {

	// No need to call Super as we're replacing the function in the NavMovementComponent.

	auto Time = GetWorld()->GetTimeSeconds();
	
	auto TankName = this->GetOwner()->GetName();

	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = this->GetOwner()->GetActorForwardVector().GetSafeNormal();

	float TurnThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	this->IntendTurnRight(TurnThrow);


	float DotP = FVector::DotProduct(AIForwardIntention, TankForward);
	this->IntendMoveForward(DotP);


	//UE_LOG(LogTemp, Warning, TEXT("%f: %s wants to move in direction: %f"), Time, *TankName, DotP);
	

	//UE_LOG(LogTemp, Warning, TEXT("%f: %s wants to move in direction: %s"), Time, *TankName, *(MoveVelocity.GetSafeNormal().ToString()));
}
