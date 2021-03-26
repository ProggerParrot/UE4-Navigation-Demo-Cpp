#include "DefaultPlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


ADefaultPlayerPawn::ADefaultPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	SetRootComponent(StaticMesh);
}



