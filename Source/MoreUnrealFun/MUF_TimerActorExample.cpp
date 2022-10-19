// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_TimerActorExample.h"

#define PrintDebugMessage(String) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, String);


// Sets default values
AMUF_TimerActorExample::AMUF_TimerActorExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMUF_TimerActorExample::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMUF_TimerActorExample::TimerFunction, 3.0f, true, 0.5f);
	
}

void AMUF_TimerActorExample::TimerFunction()
{
	CallTracker--;
	if (CallTracker == 0) {
		PrintDebugMessage("Finished Looping!");
		GetWorldTimerManager().ClearTimer(TimerHandle);
	} else {
		PrintDebugMessage("Timer Called");
	}

	PrintDebugMessage(FString::Printf(TEXT("Calls Remaining: %d"), CallTracker));
}

