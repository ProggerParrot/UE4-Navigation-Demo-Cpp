// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "NavmeshDemoGameModeBase.h"
#include "DefaultPlayerController.h"
#include "Mothership.h"

#include <ComponentReregisterContext.h>

ANavmeshDemoGameModeBase::ANavmeshDemoGameModeBase()
{
	PlayerControllerClass = ADefaultPlayerController::StaticClass();
}

void ANavmeshDemoGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnMothership();
}

void ANavmeshDemoGameModeBase::SpawnMothership()
{
	FTransform Transform;
	Transform.SetLocation(FVector(0, 0, 300));
	Transform.SetRotation(FQuat(0, 0, 0, 0));

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.bNoFail = true;
	Params.Owner = this;

	GetWorld()->SpawnActor<AMothership>(AMothership::StaticClass(), Transform, Params);
}

