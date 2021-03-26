#include "DefaultPlayerController.h"
#include "Enemy.h"
#include "Engine/World.h" 

ADefaultPlayerController::ADefaultPlayerController()
{

}


void ADefaultPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Click", IE_Pressed, this, &ADefaultPlayerController::SpawnEnemy);

	bShowMouseCursor = true;
}

void ADefaultPlayerController::SpawnEnemy()
{
	//Create Raycast from Cursor to World
    FHitResult HitResult;
    GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);



	FTransform Transform;
	Transform.SetLocation(HitResult.ImpactPoint);
	Transform.SetRotation(FQuat(0,0,0,0));

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.bNoFail = true;
	Params.Owner = this;

	GetWorld()->SpawnActor<AEnemy>(AEnemy::StaticClass(), Transform, Params);
}
