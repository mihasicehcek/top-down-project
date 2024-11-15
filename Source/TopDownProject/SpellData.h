// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpellData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOPDOWNPROJECT_API USpellData : public UObject
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell Data")
	FVector StartMouseLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell Data")
	FVector EndMouseLocation;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell Data")
	TMap<int32, int32> Parameters;

	UFUNCTION(BlueprintCallable, Category = "Spell Data")
	static USpellData* CreateSpellData(
		FVector inStartMouseLocation,
		FVector inEndMouseLocation,
	TMap<int32, int32> inParameters);
};
