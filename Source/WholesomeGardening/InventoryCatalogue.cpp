// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCatalogue.h"

// Sets default values for this component's properties
UInventoryCatalogue::UInventoryCatalogue()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryCatalogue::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryCatalogue::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
			return true;
		}
	}

	return false;
}

void UInventoryCatalogue::AddItem(FInventoryItem new_data)
{
	int id_existing = 0;
	if (ContainsItem(new_data.item_data.name, id_existing))
	{
		inventory_catalogue[id_existing].quantity += new_data.quantity;
	}
	else
	{
		inventory_catalogue.Add(new_data);
	}
}

void UInventoryCatalogue::RemoveItem(int id)
{
	int quantity = inventory_catalogue[id].quantity;
	if (quantity == 1)
		inventory_catalogue.RemoveAt(id);

	if (quantity > 1)
		inventory_catalogue[id].quantity--;
}

void UInventoryCatalogue::RemoveQuantity(int id, int amount)
{
	inventory_catalogue[id].quantity -= amount;
}

