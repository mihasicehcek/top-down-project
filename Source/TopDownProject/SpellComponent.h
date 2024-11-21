// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputAction.h"
#include "SpellComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOPDOWNPROJECT_API USpellComponent : public UObject
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Spell Component")
	FString Component;

	UFUNCTION(BlueprintCallable, Category = "Spell Component")
	static USpellComponent* CreateSpellComponent(const UInputAction* InputAction);

	UFUNCTION(BlueprintCallable, Category = "Spell Component")
	static USpellComponent* CreateSpellComponentFromString(const FString& ComponentName);
};
