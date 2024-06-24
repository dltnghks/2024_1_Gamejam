// Fill out your copyright notice in the Description page of Project Settings.


#include "NonPlayerCharacter.h"

#include "GameJam/GameJamGameMode.h"
#include "GameJam/Managers/ResourceManager.h"
#include "GameJam/Object/ObjFish.h"
#include "Kismet/GameplayStatics.h"
#include "WorldPartition/ContentBundle/ContentBundleLog.h"

class AGameJamGameMode;
// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANonPlayerCharacter::Init()
{
	UE_LOG(LogTemp, Log, TEXT("NPC Init"));
	IsDeath = false;
}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANonPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

