// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"

#include "Components/TextBlock.h"

void UInGameUI::SetCoolDown(FString CoolDown)
{
	CoolDown_Text->SetText(FText::FromString(CoolDown));
}
