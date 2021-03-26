#pragma once

#include "Mothership.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Drone.generated.h"


UCLASS()
class NAVMESHDEMO_API ADrone : public APawn
{
	GENERATED_BODY()

public:
	ADrone();


protected:
	//List of all private Functions
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	//List of all public Functions
	virtual void Tick(float DeltaTime) override;


protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "Drone")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Drone")
		USphereComponent* SphereCollider;

	UPROPERTY(EditAnywhere, Category = "Drone")
		UFloatingPawnMovement* MovementComponent;

public:

	UPROPERTY(EditAnywhere, Category = "Drone")
		AMothership* Mothership;
};
