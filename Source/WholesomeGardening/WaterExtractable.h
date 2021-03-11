// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WaterExtractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWaterExtractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHOLESOMEGARDENING_API IWaterExtractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsEmpty();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsFull();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TeleportToPoint(FVector point);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ExtractOneCharge();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsFinishedExtracting();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RefillOneCharge();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsFinishedRecharging();
};
