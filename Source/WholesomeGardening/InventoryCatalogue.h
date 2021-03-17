// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GardeningData.h"
#include "Engine/DataTable.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
	int starting_amount_of_coins;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UDataTable* dt_items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventoryItem> inventory_catalogue;

	UFUNCTION()
	void PopulateInventory();

	UFUNCTION()
	void SetCoins(int quantity) { coins = quantity; }
	UFUNCTION(BlueprintCallable)
	int GetCoins() { return coins; }
	UFUNCTION(BlueprintCallable)
	bool Withdraw(int amount);
	UFUNCTION(BlueprintCallable)
	void Deposit(int amount);

	UFUNCTION(BlueprintCallable)
	FInventoryItem GetItemData(int id);
	UFUNCTION(BlueprintCallable)
	bool ContainsItem(FString item_name, int& out_id);

	UFUNCTION(BlueprintCallable)
	void AddItem(int id, int amount);
	UFUNCTION(BlueprintCallable)
	void RemoveItem(int id, int amount);

private:
	UPROPERTY()
	int coins;
};
