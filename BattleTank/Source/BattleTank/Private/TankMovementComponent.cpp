// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double speed due to duel input
} 

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO prevent double speed due to duel input
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super as were replacing the functionality
	auto Name = GetOwner()->GetName();
	auto Speed = MoveVelocity;

	UE_LOG(LogTemp, Warning, TEXT("%s moving to %s"), *Name, *Speed.ToString());
}