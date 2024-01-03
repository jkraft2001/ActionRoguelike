// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "ASItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE__API AASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

	void Interact_Implementation(APawn* InstigatorPawn);

public:	
	UPROPERTY(EditAnywhere)
	float TargetPitch;

	// Sets default values for this actor's properties
	AASItemChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
