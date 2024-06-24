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

	UE_LOG(LogTemp, Log, TEXT("GameMode BeginPlay"));
	AObjSoapBubble* bubble = ResourceManager->Instantiate<AObjSoapBubble>(testClass);
	bubble->Init(FVector(2400.000000f,1360.000000f,315.062601f), FVector::Zero());
	UE_LOG(LogTemp, Log, TEXT("%s 생성 완료"), *bubble->GetName());
}
