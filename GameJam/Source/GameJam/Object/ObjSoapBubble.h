// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameJam/GameJamGameMode.h"
#include "ObjectPool/Poolable.h"
#include "ObjSoapBubble.generated.h"

UCLASS()
class GAMEJAM_API AObjSoapBubble : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjSoapBubble();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
	UPoolable* PoolableComponent;

	UPROPERTY(VisibleAnywhere)
	class UAudioComponent* AudioComponent;
	
	UPROPERTY()
	AGameJamGameMode* _gameMode;

	UPROPERTY(EditAnywhere, Category = " Setting")
	class UParticleSystem* _destroyParticle;

	UPROPERTY(EditAnywhere, Category = " Setting")
	class USoundBase* _spawnSound;
	
	UPROPERTY(EditAnywhere, Category = " Setting")
	class USoundBase* _destroySound;
	
	UPROPERTY()
	float _spawnTime;

	UPROPERTY()
	float _time = 0.0f;
	
protected:

	UPROPERTY()
	FVector _destination = FVector::Zero();

	UPROPERTY()
	float _moveSpeed = 100.0f;
	
	UPROPERTY()
	bool _init = false;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void Init(FVector start, FVector destination, float moveSpeed = 100.0f, float spawnTime = 5.0f);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetDestination(const FVector& destination) { _destination = destination; }
	void SetMoveSpeed(float speed) { _moveSpeed = speed; }

	void SoapBubbleDestory();
	
};
