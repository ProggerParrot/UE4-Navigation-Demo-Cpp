#include "DroneAIController.h"
#include "Drone.h"


void ADroneAIController::Tick(float DeltaTime)
{
	MoveToLocation(FVector(100.0f, 100.0f, 100.0f));

}
