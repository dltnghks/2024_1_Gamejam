// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManager.h"

#include "GameJam/GameJamGameMode.h"
#include "GameJam/Object/ObjectPool/PoolManager.h"


template <typename T>
T* UResourceManager::Instantiate(TSubclassOf<T> original)
{
	if(original.GetDefaultObject()->GetComponentByClass(UPoolable::StaticClass()))
	{
		// 오브젝트 풀에서 뽑아오기
		return _gameMode->PoolManager->Pop(original);
	}

	T* actor = NewObject<AActor>(this, original.Get());
	return actor;
}

void UResourceManager::Destory(AActor* actor)
{
	if(actor == nullptr) return;

	UPoolable* poolable = actor->GetComponentByClass<UPoolable>();
	if(poolable != nullptr)
	{
		// 오브젝트 풀에 다시 넣기
		return _gameMode->PoolManager->Push(poolable);
	}

	actor->Destroy();
	
}
