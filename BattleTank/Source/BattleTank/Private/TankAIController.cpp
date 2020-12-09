// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GetControlledTank = Cast<ATank>(GetPawn());

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank))
	{
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);


		GetControlledTank->AimAt(PlayerTank->GetActorLocation());
		GetControlledTank->Fire(); //Dont fire every frame
	}
}

