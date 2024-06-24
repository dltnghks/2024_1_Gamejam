// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Poolable.h"
#include "GameJam/GameJamGameMode.h"
#include "UObject/NoExportTypes.h"
#include "ObjPool.generated.h"

/**
 * 
 */
class UPoolable;
class AGameJamGameMode;
UCLASS()
class GAMEJAM_API UObjPool : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TSubclassOf<AActor> Original;

	UPROPERTY()
		TArray<UPoolable*> _poolStack;

	UPROPERTY()
		AGameJamGameMode* _gameMode;

	void Init(TSubclassOf<AActor> original, AGameJamGameMode* gameMode, int count = 5);

	void Push(UPoolable* poolable);

	UPoolable* Pop();
	
private:
	UPoolable* Create();
	
};