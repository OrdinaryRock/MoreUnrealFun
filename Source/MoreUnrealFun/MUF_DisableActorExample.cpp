// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_DisableActorExample.h"

#define PrintDebugMessage(String) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, String);


// Sets default values
AMUF_DisableActorExample::AMUF_DisableActorExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMUF_DisableActorExample::BeginPlay()
{
	Super::BeginPlay();

	if (bAutoDisable)
	{
		SetActive(false);
	}
	
}

// Called every frame
void AMUF_DisableActorExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrintDebugMessage("Tick!");

}

void AMUF_DisableActorExample::SetActive(bool Active)
{
	// Don't bother toggling the tick function unless this actor was originally intended to tick
	if (PrimaryActorTick.bCanEverTick == true) SetActorTickEnabled(Active);

	// If we *are* setting active, we *don't* want to be hidden (opposite)
	bool bHideMe = !Active;
	SetActorHiddenInGame(bHideMe);
	SetActorEnableCollision(Active);
}

