// Fill out your copyright notice in the Description page of Project Settings.

#include "Pokemon/EffectivenessManager.h"

float UEffectivenessManager::GetEffectiveness(const FGameplayTag& AttackType, const FGameplayTagContainer& TargetTypes) const
{
	if (!EffectivenessDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("No se ha asignado la DataTable de efectividad."));
		return 1.0f;  // Valor por defecto
	}

	float TotalMultiplier = 1.0f;

	// Obtener todas las filas de la DataTable
	TArray<FEffectivenessTableRow*> Rows;
	EffectivenessDataTable->GetAllRows(TEXT(""), Rows);

	// Buscar la fila correspondiente al tipo de ataque
	for (FEffectivenessTableRow* Row : Rows)
	{
		if (Row->AttackType.MatchesTagExact(AttackType))
		{
			// Aplicar los multiplicadores de efectividad para cada tipo de objetivo
			for (const FGameplayTag& TargetType : TargetTypes)
			{
				if (Row->EffectivenessMap.Contains(TargetType))
				{
					TotalMultiplier *= Row->EffectivenessMap[TargetType];
				}
			}
			break; // Salimos del bucle si ya hemos encontrado el tipo de ataque
		}
	}

	return TotalMultiplier;
}