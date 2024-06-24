// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShockWave.generated.h"

UCLASS()
class GAMEJAM_API AShockWave : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* ShockWave;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* DamageCollision;
	
	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
	float RemoveRate;

	float CurRemoveRate = 0;
	
public:	
	// Sets default values for this actor's properties
	AShockWave();
	
private:
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
