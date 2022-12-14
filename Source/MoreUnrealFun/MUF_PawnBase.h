// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MUF_InteractInterface.h"
#include "MUF_PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class MOREUNREALFUN_API AMUF_PawnBase : public APawn, public IMUF_InteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMUF_PawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void Interact_Implementation() override;

	virtual void InteractPure() override;

private:
	FVector MovementDirection;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	void MoveForward(float Value);
	void MoveRight(float Value);


	float Health = 0;
	float DefaultHealth = 100;
};
