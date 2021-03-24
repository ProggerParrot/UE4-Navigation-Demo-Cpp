//CPP Classses
#include "Mothership.h"
#include "Drone.h"
#include "Bullet.h"

//Components
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

//Utilitys
#include "UObject/ConstructorHelpers.h"


AMothership::AMothership()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Cube"));
	StaticMesh->SetStaticMesh(CylinderAsset.Object);


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Materials/Mothership"));
	StaticMesh->SetMaterial(0, Cast<UMaterialInterface>(MaterialAsset.Object));


	SetRootComponent(StaticMesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Detection Sphere");
	Sphere->InitSphereRadius(500.0f);
	Sphere->SetupAttachment(RootComponent);

	ShootingRange = 2000.0f;
	Cooldown = 2.0f;
	CurrentCooldown = 0.0f;
}


void AMothership::BeginPlay()
{
	Super::BeginPlay();


	for (int i = 0; i <= DronesToSpawn; ++i) {
		SpawnDrone(i);
	}
}


void AMothership::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentFokused)
	{
		SetActorRotation(CurrentFokused->GetActorLocation().Rotation());
		CheckFocusInRange();

		CurrentCooldown -= DeltaTime;
		if (CurrentCooldown <= 0.0f)
		{
			ShootAtFocused();
		}
	}
}


void AMothership::SpawnDrone(int index)
{
	float angle = (360.0f / DronesToSpawn) * index;
	float radiant = FMath::DegreesToRadians(angle);

	float x = OrbitRadius * FMath::Sin(radiant);
	float y = OrbitRadius * FMath::Cos(radiant);

	FTransform Transform;
	Transform.SetLocation(GetActorLocation() + FVector(x, y, 0));
	Transform.SetRotation(GetActorRotation().Quaternion());

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.bNoFail = true;
	Params.Owner = this;


	if (DroneClass == nullptr)
		return;
	
	ADrone* Drone = GetWorld()->SpawnActor<ADrone>(DroneClass, Transform, Params);

	//Drone->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
}

void AMothership::CheckFocusInRange()
{
	FVector Distance = CurrentFokused->GetActorLocation() - GetActorLocation();
	float Length;
	Distance.ToDirectionAndLength(Distance, Length);

	//if enemy out of shootingrange
	if (ShootingRange < Length)
	{
		CurrentFokused = nullptr;
		return;
	}
}

void AMothership::ShootAtFocused()
{
	CurrentCooldown = Cooldown;

	if (BulletClass == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("<Mothership.cpp>  No Bulletclass - Please add one in BP_Mothership!"));
		return;
	}

	FTransform Transform;
	Transform.SetLocation(GetActorLocation());
	Transform.SetRotation(GetActorRotation().Quaternion());

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.bNoFail = true;
	Params.Owner = this;

	ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, Transform, Params);


}


void AMothership::FocusEnemy(AActor* Target)
{
	CurrentFokused = Target;
	SetActorRotation(Target->GetActorLocation().Rotation());
}