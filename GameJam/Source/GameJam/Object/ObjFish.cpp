// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjFish.h"

#include "ObjectPool/Poolable.h"

// Sets default values
AObjFish::AObjFish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PoolableComponent = CreateDefaultSubobject<UPoolable>(TEXT("Poolable"));
}

// Called when the game starts or when spawned
void AObjFish::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

