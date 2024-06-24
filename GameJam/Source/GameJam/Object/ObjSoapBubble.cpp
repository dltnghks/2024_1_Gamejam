// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjSoapBubble.h"

#include "GameJam/GameJamGameMode.h"
#include "GameJam/Managers/ResourceManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AObjSoapBubble::AObjSoapBubble()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	PoolableComponent = CreateDefaultSubobject<UPoolable>(TEXT("Poolable"));
	SetRootComponent(MeshComponent);
	
}

// Called when the game starts or when spawned
void AObjSoapBubble::BeginPlay()
{
	Super::BeginPlay();
	_gameMode = Cast<AGameJamGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void AObjSoapBubble::Init(FVector destination, float moveSpeed, float spawnTime)
{
	_destination = destination;
	_moveSpeed = moveSpeed;
	_spawnTime = spawnTime;
	_time = 0;
}


// Called every frame
void AObjSoapBubble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	_time += DeltaTime;

	if(_time >= _spawnTime)
	{
		_gameMode->ResourceManager->ObjectDestory(this);
	}
	
	FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), _destination, DeltaTime, _moveSpeed);
	SetActorLocation(NewLocation);

}

