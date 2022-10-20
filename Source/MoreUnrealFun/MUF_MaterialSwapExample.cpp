// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_MaterialSwapExample.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMUF_MaterialSwapExample::AMUF_MaterialSwapExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	MaterialOne = CreateDefaultSubobject<UMaterialInterface>("MaterialOne");
	MaterialTwo = CreateDefaultSubobject<UMaterialInterface>("MaterialTwo");

}

// Called when the game starts or when spawned
void AMUF_MaterialSwapExample::BeginPlay()
{
	Super::BeginPlay();
	if (bUseMat1) Mesh->SetMaterial(0, MaterialOne);
	else Mesh->SetMaterial(0, MaterialTwo);
}