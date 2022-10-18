// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_SweepTrace.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMUF_SweepTrace::UMUF_SweepTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMUF_SweepTrace::BeginPlay()
{
	Super::BeginPlay();

	TArray<FHitResult> HitResults;
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start;
	FCollisionShape ColShape = FCollisionShape::MakeSphere(TraceRadius);

	bool bHit = GetWorld()->SweepMultiByChannel(HitResults, Start, End, FQuat::Identity, ECC_Camera, ColShape);
	DrawDebugSphere(GetWorld(), Start, TraceRadius, 15, FColor::Cyan, true);

	if (bHit)
	{
		for (FHitResult HitResult : HitResults)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, 
				FString::Printf(TEXT("Hit: %s"), *HitResult.Actor->GetName()));
		}
	}

}


// Called every frame
void UMUF_SweepTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

