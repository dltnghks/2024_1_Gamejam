// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"

#include "Components/TextBlock.h"

void UInGameUI::SetGameTime(FString GameTime)
{
	GameTime_Text->SetText(FText::FromString(GameTime));
}

void UInGameUI::SetCoolDown(FString CoolDown)
{
	CoolDown_Text->SetText(FText::FromString(CoolDown));
}

void UInGameUI::SetHP(FString HP)
{
	HP_Text->SetText(FText::FromString(HP));
}

void UInGameUI::SetScore(FString Score)
{
	Score_Text->SetText(FText::FromString(Score));
}
