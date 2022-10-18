// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMUF_PawnBase::AMUF_PawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = DefaultHealth;
}

// Called when the game starts or when spawned
void AMUF_PawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

float AMUF_PawnBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= DamageAmount;
	if (Health < 0) Health = 0;
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
	if (Health == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("YOU ARE DEAD! (DEAD, DEAD)"));
	}

	return DamageAmount;
}

void AMUF_PawnBase::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Implementation"));
}

void AMUF_PawnBase::InteractPure()
{
	UE_LOG(LogTemp, Warning, TEXT("Pure!"));
}

// Called every frame
void AMUF_PawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDirection.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void AMUF_PawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMUF_PawnBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMUF_PawnBase::MoveRight);

}

void AMUF_PawnBase::MoveForward(float Value)
{
	MovementDirection.X = FMath::Clamp(Value, -1.0f, 1.0f);
}

void AMUF_PawnBase::MoveRight(float Value)
{
	MovementDirection.Y = FMath::Clamp(Value, -1.0f, 1.0f);
}

