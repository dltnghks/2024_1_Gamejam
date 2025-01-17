// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjSoapBubble.h"

#include "Components/AudioComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
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
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bInitialVelocityInLocalSpace = false;
	ProjectileMovement->bIsHomingProjectile = true;
	SetRootComponent(MeshComponent);
	
}

// Called when the game starts or when spawned
void AObjSoapBubble::BeginPlay()
{
	Super::BeginPlay();
	_gameMode = Cast<AGameJamGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void AObjSoapBubble::Init(FVector start, FVector destination, float moveSpeed, float spawnTime)
{
	if(_spawnSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, _spawnSound, start, FRotator::ZeroRotator, 1, 1, 0);
		UE_LOG(LogTemp, Log, TEXT("Spawn Sound"));
	}
	_init = true;
	SetActorLocation(start);
	_destination = destination;
	_moveSpeed = moveSpeed;
	_spawnTime = spawnTime;
	_time = 0;
}

void AObjSoapBubble::Init(FVector start, TWeakObjectPtr<USceneComponent> target, float moveSpeed, float spawnTime)
{
	if(_spawnSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, _spawnSound, start, FRotator::ZeroRotator, 1, 1, 0);
		UE_LOG(LogTemp, Log, TEXT("Spawn Sound"));
	}
	_init = true;
	FVector dirVec = GetActorForwardVector();
	FVector newPos = start + dirVec*200;
	SetActorLocation(newPos);
	ProjectileMovement->HomingTargetComponent = target;
	ProjectileMovement->InitialSpeed = 400.0f;
	ProjectileMovement->HomingAccelerationMagnitude = 200.0f;

	dirVec = dirVec.GetSafeNormal();
	ProjectileMovement->Velocity = dirVec * ProjectileMovement->InitialSpeed;
	UE_LOG(LogTemp, Log, TEXT("ProjectileMovement->Velocity : %s"), *ProjectileMovement->Velocity.ToString());
	
	_destination = target->GetOwner()->GetActorLocation();
	_moveSpeed = moveSpeed;
	_spawnTime = spawnTime;
	_time = 0;
}


// Called every frame
void AObjSoapBubble:: Tick(float DeltaTime)
{
	if(_init == false) return;
	Super::Tick(DeltaTime);
	
	_time += DeltaTime;

	if(_time >= _spawnTime)
	{
		SoapBubbleDestory();
	}
	
	/*FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), _destination, DeltaTime, _moveSpeed);
	SetActorLocation(NewLocation);*/

}

void AObjSoapBubble::SoapBubbleDestory()
{
	if(_init == false) return;
	_init = false;
	if(_destroySound)
		UGameplayStatics::PlaySoundAtLocation(this, _destroySound, GetActorLocation(), FRotator::ZeroRotator, 1, 1, 0.3);

	if(_destroyParticle)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _destroyParticle, GetActorLocation(), FRotator::ZeroRotator, true);
	_gameMode->ResourceManager->ObjectDestory(this);
}

