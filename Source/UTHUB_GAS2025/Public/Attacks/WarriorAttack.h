// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/AttackBase.h"
#include "WarriorAttack.generated.h"

/**
 * 
 */
UCLASS()
class UTHUB_GAS2025_API UWarriorAttack : public UAttackBase
{
	GENERATED_BODY()
	virtual bool TryAttack(AActor* AttackInstigator) override;
};
