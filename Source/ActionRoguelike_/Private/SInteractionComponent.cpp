// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"
#include "SGameplayInterface.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void USInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic); // What types do we want to check for?

	AActor* MyOwner = GetOwner();

	FVector EyeLocation;
	FRotator EyeRotation;

	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End = EyeLocation + (EyeRotation.Vector() * 1000);

	FHitResult Hit;

	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);
	// LineTraceByObjectType returns the first object that fulfills a certain type. For this, we want World Dynamic.

	AActor* HitActor = Hit.GetActor();
	if(HitActor)
	{
		// Checking for null

		if(HitActor->Implements<ISGameplayInterface>()) // Only implement Interact functionality if the World Dynamic object also includes the Interact Interface.
		{
			APawn* MyPawn = Cast<APawn>(MyOwner); // MyPawn can return null without issue in this instance, unlike standard C++.

			ISGameplayInterface::Execute_Interact(HitActor, MyPawn); // Interact(APawn* InstigatorPawn), but we cast to pawn beforehand because GetOwner() only applies to AActor.

		}

	}

}

