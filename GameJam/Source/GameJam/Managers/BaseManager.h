// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseManager.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API UBaseManager : public UObject
{
	GENERATED_BODY()

protected:
	class AGameJamGameMode* _gameMode;
	
public:
	void Init(AGameJamGameMode* gameMode);
};
