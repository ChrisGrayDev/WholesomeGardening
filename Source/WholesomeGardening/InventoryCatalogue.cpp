// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCatalogue.h"

// Sets default values for this component's properties
UInventoryCatalogue::UInventoryCatalogue()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInventoryCatalogue::BeginPlay()
{
	PopulateInventory();
	Super::BeginPlay();
	SetCoins(starting_amount_of_coins);
}


// Called every frame
void UInventoryCatalogue::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryCatalogue::PopulateInventory()
{
	TArray<FItemData*> items;
	FString context_string;

	if (dt_items == nullptr)
		return;

	dt_items->GetAllRows(context_string, items);

	if (items.Num() != 0)
	{
		for (int i = 0; i < items.Num(); i++)
		{
			FInventoryItem new_item;
			new_item.item_data = *items[i];
			new_item.quantity = 0;

			inventory_catalogue.Add(new_item);
		}
	}
}

bool UInventoryCatalogue::Withdraw(int amount)
{
	bool success = false;
	int end_amount = GetCoins() - amount;
	
	if (end_amount >= 0)
	{
		success = true;
		SetCoins(end_amount);
	}

	return success;
}

void UInventoryCatalogue::Deposit(int amount)
{
	SetCoins(GetCoins() + amount);
}

FInventoryItem UInventoryCatalogue::GetItemData(int id)
{
	return inventory_catalogue[id];
}

bool UInventoryCatalogue::ContainsItem(FString item_name, int& out_id)
{
	out_id = 0;

	for (int i = 0; i < inventory_catalogue.Num(); i++)
	{
		if (inventory_catalogue[i].item_data.name == item_name)
		{
			out_id = i;

			if (inventory_catalogue[i].quantity == 0)
				return false;
			else
				return true;
		}
	}

	return false;
}

void UInventoryCatalogue::AddItem(int id, int amount)
{
	inventory_catalogue[id].quantity += amount;
}

void UInventoryCatalogue::RemoveItem(int id, int amount)
{
	int quantity = inventory_catalogue[id].quantity;
	int end_quantity = quantity - amount;

	if (end_quantity < 0)
		end_quantity = 0;

	inventory_catalogue[id].quantity = end_quantity;
}

