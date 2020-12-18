// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FGameplayAttributeData Life=100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FGameplayAttributeData MaxLife=100;
	
};
