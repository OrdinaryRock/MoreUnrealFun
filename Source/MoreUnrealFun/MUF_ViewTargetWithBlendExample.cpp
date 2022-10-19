// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_ViewTargetWithBlendExample.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMUF_ViewTargetWithBlendExample::AMUF_ViewTargetWithBlendExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	OverlapBox = CreateDefaultSubobject<UBoxComponent>("Box");
	OverlapBox->SetGenerateOverlapEvents(true);
	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AMUF_ViewTargetWithBlendExample::OnOverlapBegin);
	OverlapBox->OnComponentEndOverlap.AddDynamic(this, &AMUF_ViewTargetWithBlendExample::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AMUF_ViewTargetWithBlendExample::BeginPlay()
{
	Super::BeginPlay();

	PC = UGameplayStatics::GetPlayerController(this, 0);
	
}

void AMUF_ViewTargetWithBlendExample::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ViewTarget)
	{
		PC->SetViewTargetWithBlend(ViewTarget, BlendTime);
	}
}

void AMUF_ViewTargetWithBlendExample::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (ViewTarget)
	{
		PC->SetViewTargetWithBlend(PC->GetPawn(), BlendTime);
	}
}
