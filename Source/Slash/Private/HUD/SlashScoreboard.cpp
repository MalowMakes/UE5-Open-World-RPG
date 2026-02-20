// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashScoreboard.h"
#include "Components/AttributeComponent.h"
#include "Components/TextBlock.h"
#include "Characters/SlashCharacter.h"

void USlashScoreboard::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    APawn* PlayerPawn = GetOwningPlayerPawn();
    ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(PlayerPawn);
    if (SlashCharacter)
    {
        Attributes = SlashCharacter->GetAttributes();

        int32 Gold = Attributes->GetGold();
        if (GoldText)
        {
            GoldText->SetText(FText::AsNumber(Gold));
        }

        int32 Souls = Attributes->GetSouls();
        if (SoulsText)
        {
            SoulsText->SetText(FText::AsNumber(Souls));
        }
    }
}
