// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_InterpComponent.h"

// Sets default values for this component's properties
UMUF_InterpComponent::UMUF_InterpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Parent = GetOwner();
}


// Called when the game starts
void UMUF_InterpComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UMUF_InterpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	WaitTime -= DeltaTime;

	if (WaitTime <= 0)
	{
		if (TargetActor)
		{
			FVector ParentLoc = Parent->GetActorLocation();
			FVector TargetLoc = TargetActor->GetActorLocation();
			Parent->SetActorLocation(FMath::VInterpTo(ParentLoc, TargetLoc, DeltaTime, InterpSpeed));
		}
	}
}

