// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "MUF_TriggerVolumeBase.generated.h"

/**
 * 
 */
UCLASS()
class MOREUNREALFUN_API AMUF_TriggerVolumeBase : public ATriggerVolume
{
	GENERATED_BODY()

public:
	AMUF_TriggerVolumeBase();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
