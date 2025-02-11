// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/WarriorAttack.h"

#include "GameFramework/Actor.h"

bool UWarriorAttack::TryAttack(AActor* AttackInstigator)
{
	UE_LOG(LogTemp, Warning, TEXT("¡Ataque de guerrero!"));
	return true;  // Retornamos true indicando que el ataque fue exitoso
}