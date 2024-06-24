// Fill out your copyright notice in the Description page of Project Settings.


#include "ShockWaveNiagaraActor.h"
#include "NiagaraComponent.h"
#include "GameJamCharacter.h"

void AShockWaveNiagaraActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("ShockWave BeginPlay"))
}

void AShockWaveNiagaraActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurRemoveRate += DeltaSeconds;

	UE_LOG(LogTemp, Log, TEXT("Shockwave Tick"));
	
	if(CurRemoveRate > RemoveRate)
	{
		UE_LOG(LogTemp, Log, TEXT("ShockWaveNiagaraActor Distroy condition"));
		Destroy();
	}
}

void AShockWaveNiagaraActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor)
	{
		UE_LOG(LogTemp, Log, TEXT("ShockWaveBeginOverlap"));
	}
}
