// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_AddRadialImpulseComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMUF_AddRadialImpulseComponent::UMUF_AddRadialImpulseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMUF_AddRadialImpulseComponent::BeginPlay()
{
	Super::BeginPlay();

	Strength *= 1000;
	
	TArray<FHitResult> HitResultsArr;
	FVector Start = this->GetComponentLocation();
	FVector End = Start;
	FCollisionShape SphereShape = FCollisionShape::MakeSphere(Radius);

	bool bSweepHit = GetWorld()->SweepMultiByChannel(HitResultsArr, Start, End, FQuat::Identity, ECC_WorldStatic, SphereShape);
	DrawDebugSphere(GetWorld(), Start, Radius, 50, FColor::Orange, true);

	if (bSweepHit)
	{
		for (FHitResult HitResult : HitResultsArr)
		{
			UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(HitResult.GetActor()->GetRootComponent());
			if (MeshComp)
			{
				DrawDebugLine(GetWorld(), Start, HitResult.GetActor()->GetActorLocation(), FColor::Orange, true);
				MeshComp->AddRadialImpulse(Start, Radius, Strength, ERadialImpulseFalloff::RIF_Linear, false);
			}
		}
	}






	
}

