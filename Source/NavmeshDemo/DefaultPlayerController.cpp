#include "DefaultPlayerController.h"


void ADefaultPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Click", IE_Pressed, this, &ADefaultPlayerController::SpawnEnemy);
}

void ADefaultPlayerController::SpawnEnemy()
{
    UE_LOG(LogTemp, Warning, TEXT("SPAWN!"));

}
