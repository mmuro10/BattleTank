// Copyright Embrace IT Ltd.


#include "SprungWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PhysicsConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	SetRootComponent(PhysicsConstraintComponent);


	WheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	WheelMesh->SetupAttachment(PhysicsConstraintComponent);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	SetUpConstraints();	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::SetUpConstraints()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	
	if (!BodyRoot) { return; }
	PhysicsConstraintComponent->SetConstrainedComponents(BodyRoot, NAME_None, WheelMesh, NAME_Name);
}
