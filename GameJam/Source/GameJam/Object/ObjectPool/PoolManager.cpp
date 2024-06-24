// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolManager.h"

void UPoolManager::CreatePool(TSubclassOf<UObject> original, int count)
{
	UObjPool* pool = NewObject<UObjPool>(this, UObjPool::StaticClass());
	pool->Init(original, count);
	_pool.Add(original->GetName(), pool);
}

void UPoolManager::Push(UPoolable* poolable)
{
	FString name = poolable->GetOwner()->GetClass()->StaticClass()->GetName();
	if(_pool.Contains(name) == false)
	{
		poolable->GetOwner()->Destroy();
		return;
	}
	_pool[name]->Push(poolable);
}

UPoolable* UPoolManager::Pop(TSubclassOf<UObject> original)
{
	FString name = original->GetName();
	if(_pool.Contains(name) == false)
	{
		CreatePool(original);
	}
	return _pool[name]->Pop();
}

TSubclassOf<UObject> UPoolManager::GetOriginal(FString name)
{
	if (_pool.Contains(name) == false)
	{
		return nullptr;
	}

	return _pool[name]->Original;
}

void UPoolManager::Clear()
{
	_pool.Empty();
}
