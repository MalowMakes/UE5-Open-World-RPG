// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashHUD.h"
#include "HUD/SlashOverlay.h"
#include "HUD/SlashScoreboard.h"


void ASlashHUD::PreInitializeComponents()
{
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && SlashOverlayClass)
		{
			SlashOverlay = CreateWidget<USlashOverlay>(Controller, SlashOverlayClass);
			SlashOverlay->AddToViewport();
		}
	}
}

void ASlashHUD::BeginPlay()
{
	Super::BeginPlay();
}

void ASlashHUD::CreateScoreboard()
{
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && SlashScoreboardClass)
		{
			SlashScoreboard = CreateWidget<USlashScoreboard>(Controller, SlashScoreboardClass);
			SlashScoreboard->AddToViewport();
		}
	}
}
