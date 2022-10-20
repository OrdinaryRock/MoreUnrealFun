// Fill out your copyright notice in the Description page of Project Settings.


#include "MUF_MaterialDynamicChange.h"

// Sets default values
AMUF_MaterialDynamicChange::AMUF_MaterialDynamicChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void AMUF_MaterialDynamicChange::BeginPlay()
{
	Super::BeginPlay();
	
	// Material in first slot (must be a material instance in order for next step to work
	Material = Mesh->GetMaterial(0);
	// Convert material instance to material instance dynamic
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
	// Plug new material back into mesh
	Mesh->SetMaterial(0, DynamicMaterial);
	//Update material properties (same name as ones in editor)
	// Scalar means 1d
	// Vector means 3d (you can use FLinearColor)
	DynamicMaterial->SetScalarParameterValue("EmissiveStrength", 50);
	DynamicMaterial->SetVectorParameterValue("Color", FLinearColor::Yellow);
}