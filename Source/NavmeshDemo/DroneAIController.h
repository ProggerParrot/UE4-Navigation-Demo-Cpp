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

protected:
	virtual void BeginPlay() override;
};