// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ASDashProjectile::ASDashProjectile()
{
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	MoveComp->InitialSpeed = 6000.0f;

}

void ASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &ASDashProjectile::Explode, DetonateDelay);

}

void ASDashProjectile::Explode_Implementation()
{
	// Clear timer if the Explode was already called through another source like ONActorHit
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayedDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	EffectComp->DeactivateSystem();

	MoveComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayedTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &ASDashProjectile::TeleportInstigator, TeleportDelay);

	// Skip vase implementation as it will destory actor (we need to stay alive a bit longer to finish the 2nd timer)
	// Super::Explode_Implementation();

}

void ASDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ensure(ActorToTeleport))
	{
		// Keep instigator rotaiton or it may end up jarring.
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);

	}

}
