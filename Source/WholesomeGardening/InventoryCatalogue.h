// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GardeningData.h"
#include "InventoryCatalogue.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WHOLESOMEGARDENING_API UInventoryCatalogue : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryCatalogue();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventoryItem> inventory_catalogue;

	UFUNCTION(BlueprintCallable)
	FInventoryItem GetItemData(int id);
	UFUNCTION(BlueprintCallable)
	bool ContainsItem(FString item_name, int& out_id);

	UFUNCTION(BlueprintCallable)
	void AddItem(FInventoryItem new_data);
	UFUNCTION(BlueprintCallable)
	void RemoveItem(int id);
	UFUNCTION(BlueprintCallable)
	void RemoveQuantity(int id, int amount);
		
};
