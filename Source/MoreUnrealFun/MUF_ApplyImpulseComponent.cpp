// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_ApplyImpulseComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMUF_ApplyImpulseComponent::UMUF_ApplyImpulseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void UMUF_ApplyImpulseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	FHitResult HitResult;
	FVector Start = GetComponentLocation();
	FVector End = Start + GetComponentRotation().Vector() * TraceDistance;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);

	if (bHit)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

		UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(HitResult.GetActor()->GetRootComponent());
		if (MeshComponent && HitResult.GetActor()->IsRootComponentMovable())
		{
			FVector Forward = this->GetForwardVector();
			MeshComponent->AddImpulse(Forward * ImpulseForce * MeshComponent->GetMass());
		}
	}






















}

