// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MUF_ViewTargetWithBlendExample.generated.h"

class UBoxComponent;

UCLASS()
class MOREUNREALFUN_API AMUF_ViewTargetWithBlendExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMUF_ViewTargetWithBlendExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapBox;

	UPROPERTY(EditAnywhere, Category = "View Target")
	AActor* ViewTarget = nullptr;
	UPROPERTY(EditAnywhere, Category = "View Target")
	float BlendTime = 1.0f;
	APlayerController* PC;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
							int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
};
