// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* ControlledTank = nullptr;
	ATank* PlayerTank = nullptr;
	UWorld* World = nullptr;


	ATank* GetControlledTank() const;
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
	ATank* GetPlayerTank() const;
	
};
