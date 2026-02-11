// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "HealthPot.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AHealthPot : public AItem
{
	GENERATED_BODY()

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	UPROPERTY(EditAnywhere, Category = "HealthPot Properties")
	int32 Heal = 50;

public:
	FORCEINLINE int32 GetHeal() const { return Heal; }
	FORCEINLINE void SetHeal(int32 NumberOfSouls) { Heal = NumberOfSouls; }
};
