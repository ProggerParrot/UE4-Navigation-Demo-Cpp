// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Mothership.generated.h"



UCLASS()
class NAVMESHDEMO_API AMothership : public APawn
{
	GENERATED_BODY()

public:
	AMothership();

protected:
	//List of all private Functions
	virtual void BeginPlay() override;
	
	void SpawnDrone(int index);
	
	void CheckFocusInRange();
	
	void ShootAtFocused();


public:
	//List of all public Functions
	virtual void Tick(float DeltaTime) override;

	void FocusEnemy(AActor* Target);


protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "Mothership")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Mothership")
		TSubclassOf<class ADrone> DroneClass;

	UPROPERTY(EditAnywhere, Category = "Mothership")
		int DronesToSpawn;

	UPROPERTY(EditAnywhere, Category = "Mothership")
		double OrbitRadius;


	UPROPERTY(EditAnywhere, Category = "Combat")
		TSubclassOf<class ABullet> BulletClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
		class USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, Category = "Combat")
		double Cooldown;

	UPROPERTY(EditAnywhere, Category = "Combat")
		double ShootingRange;

	UPROPERTY(EditAnywhere, Category = "Combat")
		AActor* CurrentFokused;

	UPROPERTY(EditAnywhere, Category = "Combat")
		double CurrentCooldown;

};

