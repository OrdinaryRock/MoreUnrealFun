// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMUF_PawnBase::AMUF_PawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMUF_PawnBase::BeginPlay()
{
	Super::BeginPlay();
	
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

