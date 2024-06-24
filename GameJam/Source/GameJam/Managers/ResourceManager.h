// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "UObject/NoExportTypes.h"
#include "ResourceManager.generated.h"

/**
 * 
 */

class AActor;

UCLASS()
class GAMEJAM_API UResourceManager : public UBaseManager
{
	GENERATED_BODY()
public:
	template <typename T>
	T* Instantiate(TSubclassOf<T> original);
	
	void Destory(AActor* actor);
};