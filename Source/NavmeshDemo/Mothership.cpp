// Fill out your copyright notice in the Description page of Project Settings.


#include "Mothership.h"

// Sets default values
AMothership::AMothership()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMothership::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMothership::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMothership::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

