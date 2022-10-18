// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMUF_PawnBase::AMUF_PawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Capsule->SetupAttachment(RootComponent);

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

}

// Called to bind functionality to input
void AMUF_PawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

