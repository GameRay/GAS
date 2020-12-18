// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "MyGameplayEffectExecutionCalc.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UMyGameplayEffectExecutionCalc : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UMyGameplayEffectExecutionCalc();
	virtual  void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
