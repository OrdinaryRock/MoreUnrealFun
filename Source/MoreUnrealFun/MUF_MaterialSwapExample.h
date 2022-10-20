// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MUF_MaterialSwapExample.generated.h"

UCLASS()
class MOREUNREALFUN_API AMUF_MaterialSwapExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMUF_MaterialSwapExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* MaterialOne;
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* MaterialTwo;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterial* Material;
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInstance* MaterialInstance;

	UPROPERTY(EditAnywhere, Category = "Materials")
	bool bUseMat1;

};
