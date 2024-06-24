// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjSoapBubble.h"

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
	
}

// Called every frame
void AObjSoapBubble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), _destination, DeltaTime, _moveSpeed);
	SetActorLocation(NewLocation);

}

