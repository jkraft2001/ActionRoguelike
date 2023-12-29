// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SGameplayInterface.generated.h"

/*
Interfaces introduced a shared API without needing to specify implementation yet.
Think a treasure chest that the player wants to interact with, but also add in a body that the player needs to interact with to loot.

Depending on the interacted object, the implementation changes!
*/

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONROGUELIKE__API ISGameplayInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent) // The other option is BlueprintImplementationEvent, but that limits us to using only blueprints. Since we want C++, we're using BlueprintNativeEvent.
	void Interact(APawn* InstigatorPawn); // The function takes in the instigator (player) and passes the proper interaction through.

};
