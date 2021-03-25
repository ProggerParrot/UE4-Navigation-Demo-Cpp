#include "Drone.h"
#include "DroneAIController.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "UObject/ConstructorHelpers.h"


ADrone::ADrone()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = ADroneAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Sphere"));
	StaticMesh->SetStaticMesh(CylinderAsset.Object);


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Materials/Drone"));
	StaticMesh->SetMaterial(0, Cast<UMaterialInterface>(MaterialAsset.Object));

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	SetRootComponent(StaticMesh);
}

void ADrone::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Cast<ADroneAIController>(GetController())->MoveToLocation(FVector(0, 0, 0));

}

void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

