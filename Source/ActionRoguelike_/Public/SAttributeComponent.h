// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, USAttributeComponent*, OwningComp, float, NewHealth, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE__API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;

	// HealthMax, Stamina, Strength, ...

	// Called when the game starts
	//virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(float Delta);

	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};


// EditAnywhere - edit in BP editor and per-instance in level.
// VisibleAnywhere - 'read-only' in editor and level. (Use for components)
// EditDefaultsOnly - hide variable per-instance, edit in BP editor only.
// VisibleDefaultsOnly - 'read-only' access for variable, only in BP editor (uncommon).
// EditInstanceOnly - allow only editing of instance (eg. when placed in level)

// BlueprintReadOnly - read-only in the Blueprint scripting (does not affect 'details'-panel).
// BlueprintReadWrite - read-write access in Blueprints.

// Category = "" - dispaly only for the detail panels and blueprint context menu.