#include "OrbitWaypointsComponent.h"
#include "GameFramework/Actor.h" 

UOrbitWaypointsComponent::UOrbitWaypointsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UOrbitWaypointsComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UOrbitWaypointsComponent::SpawnWaypoints(double radius, int ammount)
{
	FVector ownerLocation = GetOwner()->GetActorLocation();

	for (int i = 0; i < ammount; ++i) {

		double angle = (360.0f / ammount) * i;
		double radiant = FMath::DegreesToRadians(angle);

		double x = radius * FMath::Sin(radiant);
		double y = radius * FMath::Cos(radiant);

		Waypoints.Add(ownerLocation + FVector(x, y, 0.0f));
	}
}

void UOrbitWaypointsComponent::GetNearestNextWaypoint(FVector& actorPosition, int& index)
{
	//loop through StaticArray
	//calculate distance between actorPosition

	//if new distance is bigger than last distance -> new distance is our next waypoint
		//return new distance + index


	//Edgecase if the drone already have an high index -> init distance will first increase | decrease | increase
		//here we just need the secound increase

}


void UOrbitWaypointsComponent::GetNextWaypoint(FVector& waypoint, int& index)
{
	index++;
	waypoint = Waypoints[index];
}



