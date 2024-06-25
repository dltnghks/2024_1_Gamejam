// Fill out your copyright notice in the Description page of Project Settings.


#include "ShockWave.h"

#include "GameJamCharacter.h"
#include "Characters/NonPlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AShockWave::AShockWave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DamageCollision = CreateDefaultSubobject<USphereComponent>(TEXT("DamageCollision"));
	DamageCollision->SetupAttachment(GetRootComponent());

	DamageCollision->SetCanEverAffectNavigation(false);
	DamageCollision->SetSphereRadius(400);
	DamageCollision->bDynamicObstacle = true;
	
	DamageCollision->OnComponentBeginOverlap.AddDynamic(this, &AShockWave::OnCollisionBeginOverlap);
} 

// Called when the game starts or when spawned
void AShockWave::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShockWave, GetActorLocation(), FRotator::ZeroRotator, true);
}

// Called every frame
void AShockWave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurRemoveRate += DeltaTime;
	
	if(CurRemoveRate > RemoveRate)
	{
		UE_LOG(LogTemp, Log, TEXT("ShockWaveNiagaraActor Distroy condition"));
		Destroy();
	}
}

void AShockWave::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("OnCollisionShockWave"));
	
	if (OtherActor && !OtherActor->IsA(AGameJamCharacter::StaticClass()))
	{
		
		ANonPlayerCharacter* OverlappedCharacter = Cast<ANonPlayerCharacter>(OtherActor);
		if (OverlappedCharacter)
		{
			OverlappedCharacter->NPCDeath();
		}
	}
}