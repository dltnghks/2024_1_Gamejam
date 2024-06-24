// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Poolable.h"
#include "UObject/NoExportTypes.h"
#include "ObjPool.generated.h"

/**
 * 
 */
class UPoolable;

UCLASS()
class GAMEJAM_API UObjPool : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TSubclassOf<AActor> Original;

	UPROPERTY()
		TArray<UPoolable*> _poolStack;
	
	void Init(TSubclassOf<AActor> original, int count = 5);

	void Push(UPoolable* poolable);

	UPoolable* Pop();
	
private:
	UPoolable* Create();
	
};