// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavmeshDemoGameModeBase.generated.h"



/**
 * 
 */
UCLASS()
class NAVMESHDEMO_API ANavmeshDemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavmeshDemoGameModeBase();


protected:
	//List of all private Functions
	virtual void BeginPlay() override;

	void SpawnMothership();
};
