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
	OnTimerSpawn.Broadcast(plant_data.plant_duration);
}

void APlant::ReachNewStage()
{
	uint8 stage = (uint8)current_growth_stage;
	if (plant_data.number_of_stages == 2)
	{
		stage = (uint8)EGrowthStage::Grown;
		current_growth_stage = (EGrowthStage) stage;
		ready_to_extract = true;
		st_mesh->SetStaticMesh(plant_data.mesh_states[1]);

		OnDirtDespawn.Broadcast();
	}
	else
	{
		stage += 1;
		current_growth_stage = (EGrowthStage) stage;
		st_mesh->SetStaticMesh(plant_data.mesh_states[stage-1]);

		if (current_growth_stage == EGrowthStage::Grown)
		{
			OnDirtDespawn.Broadcast();
			ready_to_extract = true;
		}
		else
		{
			StopGrowth();
		}
	}

	OnSmokeBurst.Broadcast();
}

int APlant::ExtractResources()
{
	int resource = FMath::RandRange(plant_data.min_resources, plant_data.max_resources);

	if (resource >= plant_data.max_resources)
		resource += FMath::RoundToInt(plant_data.max_resources / 4);

	SpawnCoins(resource);
	OnResourceExtract.Broadcast(resource);
	return resource;
}

void APlant::SpawnCoins(int resources)
{
	FActorSpawnParameters spawn_params;
	FTransform spawn_transform;
	spawn_transform.SetLocation(GetActorLocation());

	ACoinSpawner* coin_spawner = GetWorld()->SpawnActor<ACoinSpawner>(coin_spawner_class, spawn_transform, spawn_params);
	coin_spawner->InitCoins(GetActorLocation(), resources);
}
