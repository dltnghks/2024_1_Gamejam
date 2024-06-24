// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjNPCArea.h"

#include "GameJam/Characters/NonPlayerCharacter.h"
#include "WorldPartition/ContentBundle/ContentBundleLog.h"

// Sets default values
AObjNPCArea::AObjNPCArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjNPCArea::BeginPlay()
{
	Super::BeginPlay();

	for(auto elem : _npcMap)
	{
		auto characterClass = elem.Key;
		// 랜던 위치 생성
		for(int i = 0; i < elem.Value; i++)
		{
			FActorSpawnParameters parameters;
			parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			ANonPlayerCharacter* newCharacter = GetWorld()->SpawnActor<ANonPlayerCharacter>(characterClass,GetActorLocation(), FRotator::ZeroRotator, parameters);
			newCharacter->Init();
			UE_LOG(LogTemp, Log, TEXT("newCharacter Spanw"));
			_npcList.Add(newCharacter);
		}
	}
	
}

// Called every frame
void AObjNPCArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

