// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class NAVMESHDEMO_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	AEnemy();


protected:
	//List of all private Functions
	virtual void BeginPlay() override;


public:	
	//List of all public Functions
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "Enemy")
		UStaticMeshComponent* StaticMesh;


};
