#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"


ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;


	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Engine/BasicShapes/Sphere"));
	StaticMesh->SetStaticMesh(SphereAsset.Object);
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

