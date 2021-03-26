#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DefaultPlayerController.generated.h"


UCLASS()
class NAVMESHDEMO_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADefaultPlayerController();


protected:
	//List of all private Functions
	void SpawnEnemy();


public:
	//List of all public Functions
	virtual void SetupInputComponent() override;

};
