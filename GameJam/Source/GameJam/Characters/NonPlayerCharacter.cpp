// Fill out your copyright notice in the Description page of Project Settings.


#include "NonPlayerCharacter.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/SphereComponent.h"
#include "GameJam/GameJamGameMode.h"
#include "GameJam/Managers/ResourceManager.h"
#include "GameJam/Object/ObjFish.h"
#include "GameJam/Object/ObjNPCArea.h"
#include "Kismet/GameplayStatics.h"
#include "WorldPartition/ContentBundle/ContentBundleLog.h"

class AGameJamGameMode;
// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANonPlayerCharacter::Init(AObjNPCArea* npcArea)
{

	UE_LOG(LogTemp, Log, TEXT("NPC Init"));
	_init = true;
	IsDeath = false;
	IsCombat = false;
	_npcArea = npcArea;
	FNavLocation NextPatrol;
	float radius = _npcArea->SphereComponent->GetScaledSphereRadius();
	_navSystem->GetRandomPointInNavigableRadius(_npcArea->GetActorLocation(), radius, NextPatrol);
	_destination = NextPatrol;
}


// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	_navSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
}

// Called every frame
void ANonPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(_init == false ) return;
	
	FNavLocation NextPatrol;
	FVector velocity = GetVelocity();
	if (_navSystem && velocity.IsNearlyZero())
	{
		float radius = _npcArea->SphereComponent->GetScaledSphereRadius();
		if (_navSystem->GetRandomPointInNavigableRadius(_npcArea->GetActorLocation(), radius, NextPatrol))
		{
			_destination = NextPatrol;
			//UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), NextPatrol);
		}
	}

}

// Called to bind functionality to input
void ANonPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANonPlayerCharacter::NPCDeath()
{
	if(IsDeath == true || !_fishClass) return;
	IsDeath = true;
	
	AGameJamGameMode* gameMode = Cast<AGameJamGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	auto fish = gameMode->ResourceManager->Instantiate<AObjFish>(_fishClass);
	fish->SetActorLocation(GetActorLocation());
	UE_LOG(LogTemp, Log, TEXT("NPC Death"));
	Destroy();
}

