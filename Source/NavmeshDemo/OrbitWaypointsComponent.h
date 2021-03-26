#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitWaypointsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NAVMESHDEMO_API UOrbitWaypointsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOrbitWaypointsComponent();


protected:
	//List of all private Functions
	virtual void BeginPlay() override;


public:	
	//List of all public Functions
	void SpawnWaypoints(double radius, int ammount);
	
	void GetNearestNextWaypoint(FVector& actorPosition, int& index);

	void GetNextWaypoint(FVector& waypoint, int& index);

protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "Orbit")
		TArray<FVector> Waypoints;

};
