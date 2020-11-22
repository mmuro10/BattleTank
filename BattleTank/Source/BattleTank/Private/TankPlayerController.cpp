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
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *ControlledTank->GetName());
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
		GetControlledTank()->AimAt(OutHitLocation);
	}
}

//Get world location if linetrace through crosshair. If it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitlocation) const
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	//de-project the screen position of the crosshair to ta world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//line-trace along that look direction and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitlocation);
	}

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false; //line trace didn't succeed
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{

	FVector CameraWorldLocation; //to be discarded
	
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}


