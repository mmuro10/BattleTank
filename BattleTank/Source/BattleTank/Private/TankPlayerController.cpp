// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
	

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimtowardsCrosshair();
	
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName())) ;
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimtowardsCrosshair()
{
	if (!GetControlledTank()) {return; }

	FVector OutHitLocation; //out parameter
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *OutHitLocation.ToString());
		//Tell controlled tnak to aim at this point
	}
}

//Get world location if linetrace through crosshair. If it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitlocation) const
{
	OutHitlocation = FVector(1.0);
	return true;
}