// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GardeningData.h"
#include "Placeable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlaceable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHOLESOMEGARDENING_API IPlaceable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool IsOccupied(int size);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	ESoilType GetSoilType();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	FItemData GetTileData();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlaceItem(FItemData new_item);
};
