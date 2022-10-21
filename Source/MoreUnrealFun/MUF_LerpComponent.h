// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MUF_LerpComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOREUNREALFUN_API UMUF_LerpComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMUF_LerpComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UMaterialInterface* Material;
	UMaterialInstanceDynamic* DynamicMaterial;
	float TimeElapsed = 0;
	AActor* Parent = nullptr;
	FVector StartLocation;

	UPROPERTY(VisibleAnywhere, Category = "Lerp")
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, Category = "Lerp", Meta = (MakeEditWidget = true))
	FVector TargetLocation;
	UPROPERTY(EditAnywhere, Category = "Lerp")
	float LerpDuration;
	UPROPERTY(EditAnywhere, Category = "Lerp")
	float WaitTime;
		
};
