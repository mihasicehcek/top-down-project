// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellData.h"

USpellData* USpellData::CreateSpellData(FVector inStartMouseLocation, FVector inEndMouseLocation,
	TMap<int32, int32> inParameters)
{
	USpellData* SpellData = NewObject<USpellData>();
	SpellData->StartMouseLocation = inStartMouseLocation;
	SpellData->EndMouseLocation = inEndMouseLocation;
	SpellData->Parameters = inParameters;
	return SpellData;
}
