#include "Pokemon/PokemonCharacter.h"
#include "Pokemon/EffectivenessManager.h"

APokemonCharacter::APokemonCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APokemonCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializePokemon();
}

void APokemonCharacter::InitializePokemon()
{
	if (PokemonDataTable)
	{
		TArray<FPokemonAttributes*> OutData;
		PokemonDataTable->GetAllRows(TEXT(""), OutData);

		if (!OutData.IsEmpty())
		{
			FPokemonAttributes** Attr = OutData.FindByPredicate([this](FPokemonAttributes* Row)
			{
				return Row->PokemonName.Equals(PokemonName, ESearchCase::IgnoreCase);
			});

			if (Attr) Attributes = *Attr;
		}
	}
}

void APokemonCharacter::ReceiveDamage(float Damage)
{
	if (Attributes)
	{
		Attributes->Health -= Damage;
		UE_LOG(LogTemp, Warning, TEXT("¡El Pokémon ha recibido %f de daño! Salud restante: %f"), Damage, Attributes->Health);
	}
}

