// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle) {
	this->Throttle = Throttle;

	FVector ForceApplied = this->GetForwardVector() * this->Throttle * this->TrackMaxDrivingForce;
	FVector ForceLocation = this->GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(this->GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	//TODO clamp throttle value so player can't overdrive.
}


