// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlashHUD.generated.h"

class USlashOverlay;
class USlashScoreboard;
class UUserWidget;

/**
 * 
 */
UCLASS()
class SLASH_API ASlashHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CreateOverlay();

	UFUNCTION(BlueprintCallable)
	void CreateIntro();

	UFUNCTION(BlueprintCallable)
	void CreateScoreboard();

private:
	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<USlashOverlay> SlashOverlayClass;
	
	UPROPERTY()
	TObjectPtr<USlashOverlay> SlashOverlay;

	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<USlashScoreboard> SlashScoreboardClass;

	UPROPERTY()
	TObjectPtr<USlashScoreboard> SlashScoreboard;

	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<UUserWidget> SlashIntroClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> SlashIntro;

public:
	UFUNCTION(BlueprintPure)
	USlashOverlay* GetSlashOverlay() const { return SlashOverlay; }

	UFUNCTION(BlueprintPure)
	UUserWidget* GetSlashIntro() const { return SlashIntro; }
};
