// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashScoreboard.generated.h"

class UAttributeComponent;

/**
 * 
 */
UCLASS()
class SLASH_API USlashScoreboard : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAttributeComponent> Attributes;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UTextBlock> GoldText;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<class UTextBlock> SoulsText;
};
