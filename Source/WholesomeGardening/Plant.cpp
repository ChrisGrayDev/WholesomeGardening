// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"

APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	st_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlant::InitPlant(FPlantData new_data)
{
	plant_data = new_data;
	st_mesh->SetStaticMesh(plant_data.mesh_states[0]);

	OnSmokeBurst.Broadcast();
}

void APlant::StartGrowth()
{
	is_watered = true;

	GetWorld()->GetTimerManager().SetTimer(growth_timer, this, &APlant::ReachNewStage, plant_data.plant_duration);
}

void APlant::ReachNewStage()
{
	uint8 stage = (uint8)current_growth_stage;
	if (plant_data.number_of_stages == 2)
	{
		stage = (uint8)EGrowthStage::Grown;
		st_mesh->SetStaticMesh(plant_data.mesh_states[1]);
	}
	else
	{
		stage += 1;
		st_mesh->SetStaticMesh(plant_data.mesh_states[stage-1]);
	}

	OnSmokeBurst.Broadcast();
}
