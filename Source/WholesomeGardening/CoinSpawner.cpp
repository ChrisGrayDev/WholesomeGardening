// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinSpawner.h"

// Sets default values
ACoinSpawner::ACoinSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoinSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinSpawner::InitCoins(FVector loc, int number_of_coins)
{
	spawn_point = loc; number_to_spawn = number_of_coins;
	SpawnNewCoin();
}

void ACoinSpawner::SpawnNewCoin()
{
	FActorSpawnParameters spawn_params;
	FTransform spawn_transform;
	spawn_transform.SetLocation(spawn_point);
	GetWorld()->SpawnActor<ACoin>(coin_class, spawn_transform, spawn_params);
	number_spawned++;

	if (number_spawned < number_to_spawn)
		GetWorld()->GetTimerManager().SetTimer(spawn_timer, this, &ACoinSpawner::SpawnNewCoin, spawn_rate);
}
