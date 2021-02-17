// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterContainer.h"

// Sets default values
AWaterContainer::AWaterContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
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

}

bool AWaterContainer::IsEmpty_Implementation()
{
	if (is_container_infinite)
		return false;

	if (current_number_of_charges > 0)
		return true;

	return false;
}

void AWaterContainer::ExtractOneCharge_Implementation()
{
	if (!is_container_infinite)
		current_number_of_charges -= 1;
}

