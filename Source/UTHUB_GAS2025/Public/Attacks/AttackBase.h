// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AttackBase.generated.h"

/**
 * 
 */
UCLASS()
class UTHUB_GAS2025_API UAttackBase : public UObject
{
	GENERATED_BODY()

public:
	virtual bool TryAttack(AActor* AttackInstigator);
};
