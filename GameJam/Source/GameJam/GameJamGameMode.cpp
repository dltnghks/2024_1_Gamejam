// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamGameMode.h"
#include "GameJamCharacter.h"
#include "Managers/ResourceManager.h"
#include "Object/ObjSoapBubble.h"
#include "UObject/ConstructorHelpers.h"

AGameJamGameMode::AGameJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void AGameJamGameMode::BeginPlay()
{
	Super::BeginPlay();
	PoolManager = NewObject<UPoolManager>(this);
	ResourceManager = NewObject<UResourceManager>(this);

	PoolManager->Init(this);
	ResourceManager->Init(this);
	
	DestinationActor = GetWorld()->SpawnActor<AActor>(ActorClass.Get());
	DestinationActor->SetActorLocation(Destination);
}
