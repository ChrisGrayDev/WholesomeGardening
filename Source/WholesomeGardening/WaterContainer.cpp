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
	start_loc = GetActorLocation();
	target_plant = nullptr;
}

// Called every frame
void AWaterContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWaterContainer::Extract()
{
	UE_LOG(LogTemp, Display, TEXT("Extracted water"));
	is_extracting = false;
	current_number_of_charges--;

	if (target_plant != nullptr)
	{
		if (!target_plant->IsWatered())
			target_plant->StartGrowth();
	}
}

void AWaterContainer::Refill()
{
	current_number_of_charges++;
	is_refilling = false;
}

void AWaterContainer::SetTargetPlant(APlant* plant)
{
	if (plant != nullptr)
		target_plant = plant;
}

void AWaterContainer::ReturnToPoint()
{
	SetActorLocation(start_loc);
}

bool AWaterContainer::IsEmpty_Implementation()
{
	if (is_container_infinite)
		return false;

	if (current_number_of_charges <= 0)
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
	UE_LOG(LogTemp, Display, TEXT("Starting extraction"));
	is_extracting = true;
	
	GetWorld()->GetTimerManager().SetTimer(extract_timer, this, &AWaterContainer::Extract, extraction_time);
}

void AWaterContainer::TeleportToPoint_Implementation(FVector point)
{
	SetActorLocation(point + offset);
}

bool AWaterContainer::IsFinishedExtracting_Implementation()
{
	return !is_extracting;
}

void AWaterContainer::RefillOneCharge_Implementation()
{
	is_refilling = true;
	
	GetWorld()->GetTimerManager().SetTimer(extract_timer, this, &AWaterContainer::Refill, fill_time);
}

bool AWaterContainer::IsFinishedRecharging_Implementation()
{
	return !is_refilling;
}

