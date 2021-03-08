// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterContainer.h"

// Sets default values
AWaterContainer::AWaterContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWaterContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaterContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (is_extracting)
		Extract();
}

void AWaterContainer::Extract()
{
	if (current_number_of_charges > last_number_of_charges - 1.0f)
	{
		current_number_of_charges -= GetWorld()->GetDeltaSeconds();

	}
	else
	{
		current_number_of_charges = last_number_of_charges - 1.0f;
		is_extracting = false;
	}
}

void AWaterContainer::Refill()
{
	if (current_number_of_charges < last_number_of_charges + 1.0f)
	{
		current_number_of_charges -= GetWorld()->GetDeltaSeconds();
	}
	else
	{
		current_number_of_charges = last_number_of_charges + 1.0f;
		is_refilling = false;
	}
}

bool AWaterContainer::IsEmpty_Implementation()
{
	if (is_container_infinite)
		return false;

	if (current_number_of_charges > 0)
		return true;

	return false;
}

bool AWaterContainer::IsFull_Implementation()
{
	if (is_container_infinite)
		return true;

	if (current_number_of_charges >= max_number_of_charges)
		return true;
	else
		return false;
}

void AWaterContainer::ExtractOneCharge_Implementation()
{
	is_extracting = true;
	last_number_of_charges = FMath::RoundToFloat(current_number_of_charges);
}

void AWaterContainer::TeleportToPoint_Implementation(FVector point)
{
	SetActorLocation(point);
}

bool AWaterContainer::IsFinishedExtracting_Implementation()
{
	return !is_extracting;
}

void AWaterContainer::RefillOneCharge_Implementation()
{
	is_refilling = true;
	last_number_of_charges = FMath::RoundToFloat(current_number_of_charges);
}

bool AWaterContainer::IsFinishedRecharging_Implementation()
{
	return !is_refilling;
}

