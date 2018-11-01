// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include"Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

//Tick
	// Super
	// AimTowardsCrossHair()


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// Return an OUT parameter, true if hit landscape.
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;

	const float LineTraceRange = 10.0 * 100.0 * 1000.0;

	UWorld* World = nullptr;

public:
	ATank* GetControlledTank() const;
	void BeginPlay() override;

	// Start the tank moving the barrell so that a shot would hit where the crosshair intersects the world.
	void AimTowardsCrosshair();

	void Tick(float DeltaTime) override;

	bool GetLookDirection(FVector2D CrosshairScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
	
	
};
