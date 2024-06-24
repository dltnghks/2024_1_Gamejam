// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjPool.h"

void UObjPool::Init(TSubclassOf<AActor> original, int count)

{
	Original = original;
	for(int i = 0; i < count; i++)
	{
		Push(Create());
	}
}

void UObjPool::Push(UPoolable* poolable)

{
	if(poolable == nullptr) return;

	poolable->GetOwner()->SetHidden(false);
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

	poolable->GetOwner()->SetHidden(true);
	poolable->IsUsing = true;

	return poolable;
}

UPoolable* UObjPool::Create()

{
	AActor* actor = NewObject<AActor>(this, Original.Get());
	UPoolable* NewUPoolable = NewObject<UPoolable>(actor, UPoolable::StaticClass(), FName("Poolable"));
	return NewUPoolable;
}
