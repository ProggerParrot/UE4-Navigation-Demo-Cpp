// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DefaultPlayerPawn.generated.h"

UCLASS()
class NAVMESHDEMO_API ADefaultPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	ADefaultPlayerPawn();


protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "PlayerPawn")
		UStaticMeshComponent* StaticMesh;


};
