// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TopDownAttributeSet.h"
#include "VitalAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API UVitalAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Mana)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxMana)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
