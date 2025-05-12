// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlashAnimInstance.generated.h"

class ASlashCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
    class SLASH_API USlashAnimInstance : public UAnimInstance
{
    GENERATED_BODY()
public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaTime) override;

    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<ASlashCharacter> SlashCharacter;

    UPROPERTY(BlueprintReadOnly, Category = Movement)
    TObjectPtr<UCharacterMovementComponent> SlashCharacterMovement;

    UPROPERTY(BlueprintReadOnly, Category = Movement)
    float GroundSpeed;
};
