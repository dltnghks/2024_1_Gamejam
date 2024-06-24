// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjPool.h"
#include "UObject/NoExportTypes.h"
#include "PoolManager.generated.h"

/**
 * 
 */
class UPoolable;

UCLASS()
class GAMEJAM_API UPoolManager : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TMap<FString, UObjPool*> _pool;

public:
	void CreatePool(TSubclassOf<UObject> original, int count = 5);

	void Push(UPoolable* poolable);
	UPoolable* Pop(TSubclassOf<UObject> original);
	TSubclassOf<UObject> GetOriginal(FString name);
	void Clear();
};
