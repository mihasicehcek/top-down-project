// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TopDownAttributeSet.h"
#include "DamageAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API UDamageAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UDamageAttributeSet, Damage)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Resistance;
	ATTRIBUTE_ACCESSORS(UDamageAttributeSet, Resistance)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MagicPower;
	ATTRIBUTE_ACCESSORS(UDamageAttributeSet, MagicPower)
};
