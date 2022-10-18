// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_TriggerVolumeBase.h"
#include "DrawDebugHelpers.h"
#include "Engine/BrushShape.h"

#define PrintDebugMessage(String) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, String);




AMUF_TriggerVolumeBase::AMUF_TriggerVolumeBase()
{
	// Bind events
	OnActorBeginOverlap.AddDynamic(this, &AMUF_TriggerVolumeBase::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMUF_TriggerVolumeBase::OnOverlapEnd);
}

void AMUF_TriggerVolumeBase::BeginPlay()
{
	Super::BeginPlay();

	// Requires	#include "Engine/BrushShape.h"
	DrawDebugBox(GetWorld(), GetActorLocation(), Brush->Bounds.BoxExtent, FColor::Orange, true, -1, 0, 5.0f);
}

void AMUF_TriggerVolumeBase::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, "String");
	if (OtherActor && (OtherActor != this))
	{
		PrintDebugMessage("Overlap Begin!");
	}
}

void AMUF_TriggerVolumeBase::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		PrintDebugMessage("Overlap End!");
	}
}
