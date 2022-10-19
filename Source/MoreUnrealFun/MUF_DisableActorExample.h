// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MUF_DisableActorExample.generated.h"

UCLASS()
class MOREUNREALFUN_API AMUF_DisableActorExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMUF_DisableActorExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Disable")
	bool bAutoDisable = false;
	UFUNCTION(CallInEditor, Category = "Disable")
	void SetActive(bool Active);

};
