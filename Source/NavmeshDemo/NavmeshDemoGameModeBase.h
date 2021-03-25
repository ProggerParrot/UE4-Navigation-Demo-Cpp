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

	ANavmeshDemoGameModeBase();

	virtual void BeginPlay() override;

private:

	void SpawnMothership();
};
