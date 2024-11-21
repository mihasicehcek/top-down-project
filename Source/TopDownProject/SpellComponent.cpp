// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellComponent.h"

USpellComponent* USpellComponent::CreateSpellComponent(const UInputAction* InputAction)
{
	USpellComponent* NewComponent = NewObject<USpellComponent>();

	NewComponent->Component = InputAction->GetName();

	return NewComponent;
}

USpellComponent* USpellComponent::CreateSpellComponentFromString(const FString& ComponentName)
{
	USpellComponent* NewComponent = NewObject<USpellComponent>();

	NewComponent->Component = ComponentName;

	return NewComponent;
}