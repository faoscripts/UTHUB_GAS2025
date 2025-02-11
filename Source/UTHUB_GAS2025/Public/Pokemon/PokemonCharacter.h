#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "PokemonCharacter.generated.h"

USTRUCT(BlueprintType)
struct FPokemonAttributes : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PokemonName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer PokemonTypes; // Tipos del Pokémon 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<class UPokeAttack>> Attacks; // Referencia a los ataques del Pokémon
	
	void ValidateAttacks() 
	{
		const int32 MaxAttacks = 4;
		if (Attacks.Num() > MaxAttacks)
		{
			UE_LOG(LogTemp, Warning, TEXT("El Pokémon '%s' tiene más de 4 ataques. Se limitarán los primeros 4."), *PokemonName);
			Attacks.SetNum(MaxAttacks); // Limita el array a 4 ataques
		}
	}
};

UCLASS()
class UTHUB_GAS2025_API APokemonCharacter : public AActor
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPokemonAttributes* Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* PokemonDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(AllowPrivateAccess))
	FString PokemonName;

	APokemonCharacter();

	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float Damage);

protected:
	virtual void BeginPlay() override;

private:
	void InitializePokemon();
};