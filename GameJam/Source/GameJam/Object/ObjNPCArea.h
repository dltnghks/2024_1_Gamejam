// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjNPCArea.generated.h"

class ANonPlayerCharacter;

UCLASS()
class GAMEJAM_API AObjNPCArea : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "NPC Setting")
	TMap<TSubclassOf<ANonPlayerCharacter>, int> _npcMap ;

	UPROPERTY(VisibleAnywhere, Category = "NPC List")
	TArray<ANonPlayerCharacter*> _npcList;
	
	// Sets default values for this actor's properties
	AObjNPCArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
