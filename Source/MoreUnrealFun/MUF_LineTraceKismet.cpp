// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_LineTraceKismet.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UMUF_LineTraceKismet::UMUF_LineTraceKismet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMUF_LineTraceKismet::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMUF_LineTraceKismet::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start = GetOwner()->GetActorLocation();
	FVector End = GetForwardVector() * TraceDistance + Start;
	TArray<AActor*> ActorsToIgnore;
	FHitResult HitResults;

	bool bHit = UKismetSystemLibrary::LineTraceSingle(this, Start, End, UEngineTypes::ConvertToTraceType(ECC_Camera),
		false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResults, true, FLinearColor::Yellow, FLinearColor::Red, 0.1f);
	if (bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow,
			FString::Printf(TEXT("Trace Hit: %s"), *HitResults.Actor->GetName()));
	}
}

