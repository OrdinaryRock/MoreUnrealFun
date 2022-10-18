// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_AddForceComponent.h"

// Sets default values for this component's properties
UMUF_AddForceComponent::UMUF_AddForceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UMUF_AddForceComponent::BeginPlay()
{
	Super::BeginPlay();

	MeshComp = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	
}


// Called every frame
void UMUF_AddForceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Up = this->GetUpVector();
	MeshComp->AddForce(Up * Force * MeshComp->GetMass());
}

