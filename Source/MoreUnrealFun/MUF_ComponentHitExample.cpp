// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_ComponentHitExample.h"
#include "Components/BoxComponent.h"

#define PrintDebugMessage(String) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, String);


// Sets default values
AMUF_ComponentHitExample::AMUF_ComponentHitExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	HitBox = CreateDefaultSubobject<UBoxComponent>("Box");
	HitBox->OnComponentHit.AddDynamic(this, &AMUF_ComponentHitExample::OnHit);

}

// Called when the game starts or when spawned
void AMUF_ComponentHitExample::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMUF_ComponentHitExample::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	PrintDebugMessage(FString::Printf(TEXT("Hit: %s"), *OtherActor->GetName()));
}

