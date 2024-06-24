// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaterBodyOceanActor.h"
#include "Ocean.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API AOcean : public AWaterBodyOcean
{
	GENERATED_BODY()

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
};
