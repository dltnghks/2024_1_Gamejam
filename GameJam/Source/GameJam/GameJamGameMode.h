// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Object/ObjectPool/PoolManager.h"
#include "GameJamGameMode.generated.h"

class UPoolManager;
class UResourceManager;

UCLASS(minimalapi)
class AGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPoolManager* PoolManager;
	UResourceManager* ResourceManager;
	
	AGameJamGameMode();

protected:
	virtual void BeginPlay() override;
};



