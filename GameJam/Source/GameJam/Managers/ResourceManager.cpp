// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManager.h"

#include "GameJam/GameJamGameMode.h"
#include "GameJam/Object/ObjSoapBubble.h"
#include "GameJam/Object/ObjectPool/PoolManager.h"


void UResourceManager::ObjectDestory(AActor* actor)
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
