#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "EffectivenessManager.generated.h"

USTRUCT(BlueprintType)
struct FEffectivenessTableRow : public FTableRowBase
{
	GENERATED_BODY()

	// Tipo de ataque (por ejemplo, Fuego, Agua, Planta)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag AttackType;

	// Array de multiplicadores de efectividad para cada tipo de objetivo
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, float> EffectivenessMap; // Asocia cada tipo de objetivo con su multiplicador
};

UCLASS()
class UTHUB_GAS2025_API UEffectivenessManager : public UObject
{
	GENERATED_BODY()

public:
	// Referencia a la DataTable de efectividad
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effectiveness")
	UDataTable* EffectivenessDataTable;

	// Método para obtener la efectividad
	UFUNCTION(BlueprintCallable, Category = "Effectiveness")
	float GetEffectiveness(const FGameplayTag& AttackType, const FGameplayTagContainer& TargetTypes) const;
};