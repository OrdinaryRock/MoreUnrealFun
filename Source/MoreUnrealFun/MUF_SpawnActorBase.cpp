// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_SpawnActorBase.h"

// Sets default values
AMUF_SpawnActorBase::AMUF_SpawnActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMUF_SpawnActorBase::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
	
}
