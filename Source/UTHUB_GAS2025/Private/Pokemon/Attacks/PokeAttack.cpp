// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/Attacks/PokeAttack.h"
#include "Pokemon/PokemonCharacter.h"
#include "Pokemon/EffectivenessManager.h"

bool UPokeAttack::TryAttack(AActor* Target)
{
	APokemonCharacter* TargetPokemon = Cast<APokemonCharacter>(Target);
	if (TargetPokemon)
	{
		UEffectivenessManager* EffectivenessManager = NewObject<UEffectivenessManager>();
		EffectivenessManager->EffectivenessDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/EffectivenessDataTable.EffectivenessDataTable"));

		float Effectiveness = EffectivenessManager->GetEffectiveness(AttackData.AttackType, TargetPokemon->Attributes->PokemonTypes);
		float FinalDamage = AttackData.Damage * Effectiveness;

		TargetPokemon->ReceiveDamage(FinalDamage);

		UE_LOG(LogTemp, Warning, TEXT("¡Ataque de tipo %s con efectividad x%.1f!"), *AttackData.AttackType.ToString(), Effectiveness);
		return true;
	}

	return false;
}