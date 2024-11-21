#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputAction.h"
#include "SpellComponent.h"
#include "Abilities/GameplayAbility.h"
#include "FSpell.generated.h"

UCLASS(Blueprintable)
class TOPDOWNPROJECT_API UFSpell : public UObject
{
	GENERATED_BODY()

private:
	TSubclassOf<UGameplayAbility> FireBallAbilityClass;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell")
	int32 Element;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell")
	int32 Form;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell")
	TMap<int32, int32> Parameters;

	UFSpell();

	UFUNCTION(BlueprintCallable, Category = "Spell")
	FString ToString() const;

	UFUNCTION(BlueprintCallable, Category = "Spell")
	bool CreateSpellAbility(TSubclassOf<UGameplayAbility>& OutAbilityReference);

	UFUNCTION(BlueprintCallable, Category = "Spell")
	static bool CreateSpell(const TArray<USpellComponent*>& InputActions, UFSpell*& OutSpell);
};
