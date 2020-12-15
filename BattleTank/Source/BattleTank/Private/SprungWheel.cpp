// Copyright Embrace IT Ltd.


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MassMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	SetRootComponent(MassMesh);

	WheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	WheelMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PhysicsConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	PhysicsConstraintComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

