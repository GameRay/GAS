// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayEffectExecutionCalc.h"

#include "BaseAttributeSet.h"

struct RPGDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Life);
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxLife);
	RPGDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,MaxLife,Source,true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,Life,Target,false);
	}
	
};

static const RPGDamageStatics&DamageStatics()
{
	static  RPGDamageStatics DmgeStatics;
	return  DmgeStatics;
}
UMyGameplayEffectExecutionCalc::UMyGameplayEffectExecutionCalc()
{
	RelevantAttributesToCapture.Add(DamageStatics().LifeDef);
	RelevantAttributesToCapture.Add(DamageStatics().MaxLifeDef);
}

void UMyGameplayEffectExecutionCalc::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{

	const FGameplayEffectSpec&Spec=ExecutionParams.GetOwningSpec();
	const FGameplayTagContainer*SourceTags= Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer*TargetTags= Spec.CapturedSourceTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParameters ;
	EvaluateParameters.SourceTags=SourceTags;
	EvaluateParameters.TargetTags=TargetTags;

	float Life=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().LifeDef,EvaluateParameters,Life);
	
	float MaxLife=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().MaxLifeDef,EvaluateParameters,MaxLife);

	float DamageDone=0.5*Life;
	if(DamageDone>0.0f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().LifeProperty,EGameplayModOp::Additive,-DamageDone));
	}
	
}
