// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "NavmeshDemoGameModeBase.h"
#include "DefaultPlayerController.h"


ANavmeshDemoGameModeBase::ANavmeshDemoGameModeBase()
{
	PlayerControllerClass = ADefaultPlayerController::StaticClass();
	
}
