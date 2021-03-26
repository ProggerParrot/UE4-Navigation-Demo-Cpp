#include "Drone.h"
#include "DroneAIController.h"

#include "UObject/ConstructorHelpers.h"


ADrone::ADrone()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = ADroneAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Engine/BasicShapes/Sphere"));
	StaticMesh->SetStaticMesh(SphereAsset.Object);


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Materials/Drone"));
	StaticMesh->SetMaterial(0, Cast<UMaterialInterface>(MaterialAsset.Object));

	SetRootComponent(StaticMesh);


	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	SphereCollider = CreateDefaultSubobject<USphereComponent>("Detection Sphere");
	SphereCollider->InitSphereRadius(500.0f);
	SphereCollider->SetupAttachment(RootComponent);

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ADrone::OnOverlapBegin);
}

void ADrone::BeginPlay()
{
	Super::BeginPlay();
}

void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADrone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Enemy"))
	{
		Mothership->FocusEnemy(OtherActor);
		UE_LOG(LogTemp, Warning, TEXT("DRONE DETECTED ENEMY!!!"));
	}
}
