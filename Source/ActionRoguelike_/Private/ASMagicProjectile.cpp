// Fill out your copyright notice in the Description page of Project Settings.


#include "ASMagicProjectile.h"
#include "SAttributeComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AASMagicProjectile::AASMagicProjectile()
{
	SphereComp->SetSphereRadius(20.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AASMagicProjectile::OnActorOverlap);

	DamageAmount = 20.0f;

}

void AASMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(OtherActor->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			// minus in front of DamageAmount to apply the change as damage, not healing
			AttributeComp->ApplyHealthChange(-DamageAmount);

			// Only explode when we hit something valid
			Explode();
		}
	}
}
