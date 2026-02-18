// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetHealthBarPercent(float Percent);
	void SetStaminaBarPercent(float Percent);
	void SetGold(int32 Gold);
	void SetSouls(int32 Souls);
	void SetEquipTextVisibility(ESlateVisibility EquipVisibility);

private:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UProgressBar> HealthProgressBar;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UProgressBar> StaminaProgressBar;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UTextBlock> GoldText;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UTextBlock> SoulsText;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UTextBlock> EquipText;
	
};
