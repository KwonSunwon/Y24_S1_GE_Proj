// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"

// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn());

	AIController = Cast<AAIController>(GetController());
	if(!AIController)
		UE_LOG(LogTemp, Error, TEXT("AIController is null"));
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!m_isAttacking && !m_isHit)
		AiMove();
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float actualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Display, TEXT("%s Enemy took damage : %f"), *GetName(), actualDamage);

	PlayAnimMontage

		return actualDamage;
}

void AEnemy::AiMove(float delay)
{
	GetWorldTimerManager().SetTimer(m_timerHandle, delay, false);
	AIController->MoveToActor(player.Get(), 0.f);
}

