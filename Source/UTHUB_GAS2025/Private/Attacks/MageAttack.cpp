// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/MageAttack.h"
#include "GameFramework/Actor.h"

bool UMageAttack::TryAttack(AActor* AttackInstigator)
{
	UE_LOG(LogTemp, Warning, TEXT("¡Ataque de mago!"));
	return true;  // Retornamos true indicando que el ataque fue exitoso
}