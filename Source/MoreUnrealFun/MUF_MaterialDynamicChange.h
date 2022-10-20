// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MUF_MaterialDynamicChange.generated.h"

UCLASS()
class MOREUNREALFUN_API AMUF_MaterialDynamicChange : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMUF_MaterialDynamicChange();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UMaterialInterface* Material;

};
