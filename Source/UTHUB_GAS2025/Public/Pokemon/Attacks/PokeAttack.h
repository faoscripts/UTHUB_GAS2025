#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "PokeAttack.generated.h"

USTRUCT(BlueprintType)
struct FAttackAttributes : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag AttackType; // Tipo del ataque (Fuego, Agua, etc.)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxUses;
};

UCLASS(Blueprintable)
class UTHUB_GAS2025_API UPokeAttack : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttackAttributes AttackData;

	UFUNCTION(BlueprintCallable)
	virtual bool TryAttack(AActor* Target);
};
