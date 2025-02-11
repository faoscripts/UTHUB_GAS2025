// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/ArcherAttack.h"

#include "GameFramework/Actor.h"

bool UArcherAttack::TryAttack(AActor* AttackInstigator)
{
	UE_LOG(LogTemp, Warning, TEXT("¡Ataque de arquero!"));
	return true;  // Retornamos true indicando que el ataque fue exitoso
}