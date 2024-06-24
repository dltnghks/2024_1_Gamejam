// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraActor.h"
#include "ShockWaveNiagaraActor.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API AShockWaveNiagaraActor : public ANiagaraActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
	float RemoveRate;

	float CurRemoveRate = 0;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
