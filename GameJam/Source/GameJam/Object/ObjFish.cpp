// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjFish.h"

#include "Components/SphereComponent.h"
#include "GameJam/GameJamCharacter.h"
#include "GameJam/GameJamGameMode.h"
#include "GameJam/Managers/ResourceManager.h"
#include "ObjectPool/Poolable.h"
#include "ObjectPool/PoolManager.h"

// Sets default values
AObjFish::AObjFish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PoolableComponent = CreateDefaultSubobject<UPoolable>(TEXT("Poolable"));
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(GetRootComponent());

	Collision->SetCanEverAffectNavigation(false);
	Collision->SetSphereRadius(100);
	Collision->bDynamicObstacle = true;
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AObjFish::OnCollisionBeginOverlap);
}

// Called when the game starts or when spawned
void AObjFish::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjFish::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor->IsA(AGameJamCharacter::StaticClass()))
	{
		AGameJamCharacter* character = Cast<AGameJamCharacter>(OtherActor);

		character->AddScore();
		
		GetWorld()->GetAuthGameMode<AGameJamGameMode>()->ResourceManager->ObjectDestory(this);
	}
}

// Called every frame
void AObjFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

