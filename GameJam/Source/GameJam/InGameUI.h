// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameUI.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* GameTime_Text;
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* CoolDown_Text;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* HP_Text;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* Score_Text;
	
public:
	void SetGameTime(FString GameTime);
	void SetCoolDown(FString CoolDown);
	void SetHP(FString HP);
	void SetScore(FString Score);
};
