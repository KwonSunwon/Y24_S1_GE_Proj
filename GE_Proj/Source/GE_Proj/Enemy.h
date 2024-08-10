// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class GE_PROJ_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
	void AiMove(float delay = 0.f);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool m_isAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool m_isHit = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool m_isAlive = true;

private:
	TWeakObjectPtr<class APawn> player;
	TObjectPtr<class AAIController> AIController;

protected:
	FTimerHandle m_timerHandle;
};
