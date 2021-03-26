// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DroneAIController.generated.h"

/**
 * 
 */
UCLASS()
class NAVMESHDEMO_API ADroneAIController : public AAIController
{
	GENERATED_BODY()

public:
	ADroneAIController();


public:
	//List of all public Functions
	void Tick(float DeltaTime) override;

};
