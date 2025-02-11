// Fill out your copyright notice in the Description page of Project Settings.
#include "Attacks/AttackBase.h"

bool UAttackBase::TryAttack(AActor* AttackInstigator)
{
	UE_LOG(LogTemp, Warning, TEXT("Ataque ejecutado por: %s"), *AttackInstigator->GetName());
	return true;
}
