// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_LineTraceWorld.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMUF_LineTraceWorld::UMUF_LineTraceWorld()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMUF_LineTraceWorld::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMUF_LineTraceWorld::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start = GetOwner()->GetActorLocation();
	FVector End = GetForwardVector() * TraceDistance + Start;

	FHitResult HitResults;
	FCollisionQueryParams TraceParams;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResults, Start, End, ECC_Visibility, TraceParams);

	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

	if (bHit) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Orange, FString::Printf(TEXT("Trace Hit: %s"), *HitResults.GetActor()->GetName()));
	}
}

