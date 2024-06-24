// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NonPlayerCharacter.generated.h"

UCLASS()
class GAMEJAM_API ANonPlayerCharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly)
	FVector _destination;
	
	UPROPERTY()
	bool IsDeath = false;

	UPROPERTY(EditAnyWhere, Category = "fish")
	TSubclassOf<class AObjFish> _fishClass;

	UPROPERTY()
	class AObjNPCArea* _npcArea;

	UPROPERTY()
	class UNavigationSystemV1* _navSystem;

	UPROPERTY()
	bool _init = false;;

public:
	// Sets default values for this character's properties
	ANonPlayerCharacter();

	void Init(class AObjNPCArea* npcArea);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void NPCDeath();

};
