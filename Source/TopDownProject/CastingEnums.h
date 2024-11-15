#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECastingType : uint8
{
	Fire,
	Space
};

UENUM(BlueprintType)
enum class ECastState : uint8
{
	Idle,
	SelectingElement,
	SelectingForm,
	SelectingParameterType,
	InputtingParameterValue
};
