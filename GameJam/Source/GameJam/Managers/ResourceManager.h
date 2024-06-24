// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseManager.h"
#include "GameJam/GameJamGameMode.h"
#include "GameJam/Object/ObjectPool/Poolable.h"
#include "GameJam/Object/ObjectPool/PoolManager.h"
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
	void ObjectDestory(AActor* actor);
};

template <typename T>
T* UResourceManager::Instantiate(TSubclassOf<T> original)
{
	auto components = Cast<AActor>(original.GetDefaultObject())->K2_GetComponentsByClass(UPoolable::StaticClass());
	if(components.Num() >= 1)
	{
		// 오브젝트 풀에서 뽑아오기
		return Cast<T>(_gameMode->PoolManager->Pop(original)->GetOwner());		
	}
	UE_LOG(LogTemp, Log, TEXT("---%s 생성, %d"), *original->GetName(), components.Num()	);
	T* actor = _gameMode->GetWorld()->SpawnActor<T>(original.Get());
	return actor;
};