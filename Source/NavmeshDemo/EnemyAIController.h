#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"


UCLASS()
class NAVMESHDEMO_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	

protected:
	//List of all private Functions
	virtual void BeginPlay() override;

};
