// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UHealthBarComponent;
class UPawnSensingComponent;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
struct FAIStimulus;

UCLASS()
class SLASH_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

	/** <AActor> */
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Destroyed() override;

	/** <IHitInterface> */
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

protected:
	/** <AActor> */
	virtual void BeginPlay() override;

	/** <ABaseCharacter> */
	virtual bool CanAttack() override;
	virtual void Attack() override;
	virtual void AttackEnd() override;
	virtual void ApplyDamage(float DamageAmount) override;
	virtual void PlayDeathMontage() override;
	virtual void Die() override;	

	/** <AEnemy> */
	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;

private:
	/**
	* AI Behavior
	*/
	void CheckPatrolTarget();
	AActor* ChoosePatrolTarget();
	void StartPatrolling();
	void PatrolTimerFinished();
	void CheckCombatTarget();
	void ChaseTarget();
	void LoseInterest();
	bool IsOutsideCombatRadius();
	bool IsOutsideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsEngaged();
	bool IsAttacking();
	bool IsDead();
	void StartAttackTimer();
	void ClearAttackTimer();
	void HideHealthBar();
	void ShowHealthBar();
	void MoveToTarget(AActor* Target);
	bool InTargetRange(AActor* Target, double Radius);

	UFUNCTION()
	void PawnSeen(AActor* Actor, FAIStimulus Stimulus); // Callback for OnPawnSeen in UPawnSensingComponent

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHealthBarComponent> HealthBarWidget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPawnSensingComponent> PawnSensing;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UAIPerceptionComponent> AIPerceptionComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	UPROPERTY(EditAnywhere)
	TSubclassOf <class AWeapon> WeaponClass;

	UPROPERTY()
	TObjectPtr<class AAIController> EnemyController;

	/**
	* Patrol Parameters
	*/

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TObjectPtr<AActor> PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<TObjectPtr<AActor>> PatrolTargets;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	double PatrolRadius = 200.f;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float PatrolSpeed = 125.f;

	FTimerHandle PatrolTimer;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float PatrolWaitMin = 5.f;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float PatrolWaitMax = 10.f;

	/**
	* Combat Parameters
	*/

	UPROPERTY()
	TObjectPtr<AActor> CombatTarget;

	UPROPERTY(EditAnywhere, Category = Combat)
	float ChaseSpeed = 350.f;

	UPROPERTY(EditAnywhere, Category = Combat)
	double CombatRadius = 800.f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float AttackRadius = 150.f;

	FTimerHandle AttackTimer;

	UPROPERTY(EditAnywhere, Category = Combat)
	float AttackMin = 0.2f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float AttackMax = 0.6f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float DeathLifeSpan = 8.f;
};
