#include "FSpell.h"

UFSpell::UFSpell()
	: Element(0), Form(0)
{
    static ConstructorHelpers::FClassFinder<UGameplayAbility> BlueprintClass(TEXT("/Game/TopDown/Blueprints/Abilities/GA_CastFireBall.GA_CastFireBall_C"));
    if (BlueprintClass.Succeeded())
    {
        FireBallAbilityClass = BlueprintClass.Class;
    }
}

FString UFSpell::ToString() const
{
	return FString::Printf(TEXT("Element: %d, Form: %d, Parameters: %s"),
		Element,
		Form,
		*FString::JoinBy(Parameters, TEXT(", "), [](const TPair<int32, int32>& Pair) {
			return FString::Printf(TEXT("(%d: %d)"), Pair.Key, Pair.Value);
		})
	);
}

bool UFSpell::CreateSpellAbility(TSubclassOf<UGameplayAbility>& OutAbilityReference)
{
    if (Element == 1 && Form == 1)
    {
        OutAbilityReference = FireBallAbilityClass;
        return true;
    }
    return false;
}

bool UFSpell::CreateSpell(const TArray<USpellComponent*>& InputActions, UFSpell*& OutSpell)
{
    if (!OutSpell)
    {
        OutSpell = NewObject<UFSpell>();
        if (!OutSpell)
        {
            return false;
        }
    }
    
    TMap<FString, int32> ReplacementMap = {
        {TEXT("IA_1Parameter"), 1},
        {TEXT("IA_2Parameter"), 2},
        {TEXT("IA_3Parameter"), 3}
    };

    TMap<FString, int32> ReplacementParameterMap = {
        {TEXT("IA_Press1"), 1},
        {TEXT("IA_Press2"), 2},
        {TEXT("IA_Press3"), 3},
        {TEXT("IA_Press4"), 4},
        {TEXT("IA_Press5"), 5}
    };
    
    if (InputActions.Num() < 4)
    {
        return false;
    }

    if (InputActions[0]->Component != "IA_SelectElement")
    {
        return false;
    }

    if (int32* FoundValue = ReplacementMap.Find(InputActions[1]->Component))
    {
        OutSpell->Element = *FoundValue;
    }else{
        return false;
    }

    if (InputActions[2]->Component != "IA_SelectForm")
    {
        return false;
    }

    if (int32* FoundValue = ReplacementMap.Find(InputActions[3]->Component))
    {
        OutSpell->Form = *FoundValue;
    }else{
        return false;
    }

    if (InputActions.Num() > 4)
    {
        for (int i = 5; i < InputActions.Num(); i += 2)
        {
            if (int32* ParameterId = ReplacementMap.Find(InputActions[i]->Component))
            {
                if (int32* ParameterValue = ReplacementParameterMap.Find(InputActions[i + 1]->Component))
                {
                    if (int32* FoundValue = OutSpell->Parameters.Find(*ParameterId))
                    {
                        if (*FoundValue == (*ParameterValue - 1))
                        {
                            (*FoundValue)++;
                        }
                    }else
                    {
                        if (*ParameterValue == 1)
                        {
                            OutSpell->Parameters.Add(*ParameterId, 1);
                        }else
                        {
                            return false;
                        }
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    
    return true;
}

