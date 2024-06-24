// Fill out your copyright notice in the Description page of Project Settings.


#include "Ocean.h"

#include "GameJamCharacter.h"

void AOcean::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor && OtherActor->IsA(AGameJamCharacter::StaticClass()))
	{
		AGameJamCharacter* Character = Cast<AGameJamCharacter>(OtherActor);
		Character->EnterWater();
	}
}

void AOcean::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if(OtherActor && OtherActor->IsA(AGameJamCharacter::StaticClass()))
	{
		AGameJamCharacter* Character = Cast<AGameJamCharacter>(OtherActor);
		Character->ExitWater();
	}
}
