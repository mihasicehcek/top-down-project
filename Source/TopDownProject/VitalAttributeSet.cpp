// Fill out your copyright notice in the Description page of Project Settings.


#include "VitalAttributeSet.h"

void UVitalAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if(Attribute == GetHealthAttribute()){
		NewValue = FMath::Clamp(NewValue, 0, MaxHealth.GetCurrentValue());
	}
}

