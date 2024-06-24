// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API UAnimInstanceCharacter : public UAnimInstance
{
	GENERATED_BODY()
protected:
    UPROPERTY(BlueprintReadOnly, Category = "State", Meta = (AllowPrivateAccess = true))
    float Speed;

    UPROPERTY(BlueprintReadOnly, Category = "State", Meta = (AllowPrivateAccess = true))
    bool IsDeath = false;

    UPROPERTY(EditAnywhere, Category = Pawn, Meta = (AllowPrivateAccess = true))
    UAnimMontage* _hitMontage;

    UPROPERTY(EditAnywhere, Category = Pawn, Meta = (AllowPrivateAccess = true))
    UAnimMontage* _deathMontage;
    
public:

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

    void PlayDeathMontage();
    void PlayHitMontage();

    UFUNCTION(BlueprintCallable)
    void PlayAnimMontage(class UAnimMontage* _playMontage);
};
