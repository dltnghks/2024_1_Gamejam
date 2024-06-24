// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjPool.h"
#include "GameJam/Managers/BaseManager.h"
#include "UObject/NoExportTypes.h"
#include "PoolManager.generated.h"

/**
 * 
 */
class UPoolable;

UCLASS()
class GAMEJAM_API UPoolManager : public UBaseManager
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TMap<FString, UObjPool*> _pool;

public:
	void CreatePool(TSubclassOf<AActor> original, int count = 5);

	void Push(UPoolable* poolable);
	UPoolable* Pop(TSubclassOf<AActor> original);
	TSubclassOf<AActor> GetOriginal(FString name);
	void Clear();
};
