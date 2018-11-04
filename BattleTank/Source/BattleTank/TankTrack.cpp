// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle) {
	this->Throttle = Throttle;

	if (this->Throttle > 0.0f) {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s throttle is at %f"), Time, *(this->GetName()), this->Throttle);
	}

	FVector ForceApplied = this->GetForwardVector() * this->Throttle * this->TrackMaxDrivingForce;
	FVector ForceLocation = this->GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(this->GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	//TODO clamp throttle value so player can't overdrive.
}


