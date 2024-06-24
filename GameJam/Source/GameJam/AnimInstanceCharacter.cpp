// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstanceCharacter.h"

// 매 프레임마다 수행(큰 오버헤드는 아님)
void UAnimInstanceCharacter::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size(); // speed에 pawn의 velocity size를 받아 옴
	}
}

void UAnimInstanceCharacter::PlayAnimMontage(class UAnimMontage* _playMontage)
{
	if (_playMontage && !Montage_IsPlaying(_playMontage))
	{
		Montage_Play(_playMontage);
	}
}

void UAnimInstanceCharacter::PlayDeathMontage()
{
	if (!Montage_IsPlaying(_deathMontage))
	{
		Montage_Play(_deathMontage);
	}
	IsDeath = true;
}

void UAnimInstanceCharacter::PlayHitMontage()
{
	if (!Montage_IsPlaying(_hitMontage))
	{
		Montage_Play(_hitMontage);
	}
}