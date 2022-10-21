// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_LerpComponent.h"

// Sets default values for this component's properties
UMUF_LerpComponent::UMUF_LerpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Parent = GetOwner();
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}


// Called when the game starts
void UMUF_LerpComponent::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetComponentLocation();
	// Fix required to make this work. Not shown in tutorial
	// TargetLocation passed in from editor is widget location RELATIVE to root component
	// Must offset StartLocation by TargetLocation in order to get ACTUAL intended target location
	TargetLocation = StartLocation + TargetLocation;
	Material = Mesh->GetMaterial(0);
	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
	DynamicMaterial->SetVectorParameterValue("Color", FLinearColor::Blue);
	Mesh->SetMaterial(0, DynamicMaterial);
}


// Called every frame
void UMUF_LerpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	WaitTime -= DeltaTime;
	if (WaitTime <= 0)
	{
		if (TimeElapsed < LerpDuration)
		{
			float lerpPercent = TimeElapsed / LerpDuration;
			Parent->SetActorLocation(FMath::Lerp(StartLocation, TargetLocation, lerpPercent));
			DynamicMaterial->SetVectorParameterValue("Color", FMath::Lerp(FLinearColor::Blue, FLinearColor::Red, lerpPercent));
			TimeElapsed += DeltaTime;
		}
	}
}

