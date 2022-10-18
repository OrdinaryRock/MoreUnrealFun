// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MUF_SphereTraceKismet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOREUNREALFUN_API UMUF_SphereTraceKismet : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMUF_SphereTraceKismet();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Trace")
	float TraceRadius = 500.0f;
		
};
