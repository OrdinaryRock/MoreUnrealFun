// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_SphereTraceKismet.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UMUF_SphereTraceKismet::UMUF_SphereTraceKismet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMUF_SphereTraceKismet::BeginPlay()
{
	Super::BeginPlay();

	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	TArray<FHitResult> HitResultsArr;

	bool bHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), Start, End, TraceRadius, 
														UEngineTypes::ConvertToTraceType(ECC_Camera), false, ActorsToIgnore, 
														EDrawDebugTrace::ForDuration, HitResultsArr, true, 
														FLinearColor::Green, FLinearColor::Blue, 60.0f);
	if (bHit)
	{
		for (FHitResult HitResult : HitResultsArr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Blue, 
				FString::Printf(TEXT("Hit: %s"), *HitResult.Actor->GetName()));
		}
	}
}

