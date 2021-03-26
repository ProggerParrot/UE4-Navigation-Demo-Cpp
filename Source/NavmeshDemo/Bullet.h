// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class NAVMESHDEMO_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:
	ABullet();


protected:
	//List of all private Functions
	virtual void BeginPlay() override;


public:	
	//List of all public Functions
	virtual void Tick(float DeltaTime) override;


protected:
	//List of all UPropertys
	UPROPERTY(EditAnywhere, Category = "Bullet")
		UStaticMeshComponent* StaticMesh;

};
