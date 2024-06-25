// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameJamGameMode.generated.h"

class UPoolManager;
class UResourceManager;

UCLASS(minimalapi)
class AGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category ="Set Class")
	TSubclassOf<class AObjSoapBubble> testClass;

public:
	UPROPERTY()
	UPoolManager* PoolManager;

	UPROPERTY()
	UResourceManager* ResourceManager;

	UPROPERTY(EditAnywhere, Category = "Destination")
	FVector Destination;

	UPROPERTY(EditAnywhere, Category = "Destination")
	TSubclassOf<AActor> ActorClass;
	
	UPROPERTY(EditAnywhere, Category = "Destination")
	class AActor* DestinationActor;
	
	AGameJamGameMode();

protected:
	virtual void BeginPlay() override;
};



