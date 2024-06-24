// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected:

	UPROPERTY()
	FVector _destination = FVector::Zero();

	UPROPERTY()
	float _moveSpeed = 100.0f;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetDestination(const FVector& destination) { _destination = destination; }
	void SetMoveSpeed(float speed) { _moveSpeed = speed; }
	
};
