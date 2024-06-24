// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjPool.h"

#include "GameJam/GameJamGameMode.h"

void UObjPool::Init(TSubclassOf<AActor> original, AGameJamGameMode* gameMode, int count)

{
	_gameMode  = gameMode;
	Original = original;
	for(int i = 0; i < count; i++)
	{
		Push(Create());
	}
}

void UObjPool::Push(UPoolable* poolable)

{
	if(poolable == nullptr) return;

	poolable->GetOwner()->SetHidden(true);
	poolable->IsUsing = false;

	_poolStack.Push(poolable);
}

UPoolable* UObjPool::Pop()

{
	UPoolable* poolable;
	if (_poolStack.Num() > 0)
	{
		poolable = _poolStack.Pop();
	}
	else
	{
		poolable = Create();
	}

	poolable->GetOwner()->SetHidden(false);
	poolable->IsUsing = true;

	return poolable;
}

UPoolable* UObjPool::Create()
{
	AActor* actor = _gameMode->GetWorld()->SpawnActor<AActor>(Original.Get());
	auto component = actor->K2_GetComponentsByClass(UPoolable::StaticClass());
	UPoolable* NewUPoolable = Cast<UPoolable>(component[0]);
	return NewUPoolable;
}
