// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> Projectile;
		//UClass* ProjectileBlueprint = nullptr; //Alternative https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf

	UTankBarrel* Barrel = nullptr;
};
