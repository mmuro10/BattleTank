// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	//start the tank moving the barrel so that a shot will hit @ crosshair intersects the world
	void AimtowardsCrosshair();

	ATank* GetControlledTank() const; 

	// Called every frame
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	//Return an OUT paramerter, true if hit landscapre
	bool GetSightRayHitLocation(FVector& OutHitlocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
	
};