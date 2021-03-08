// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringCan.h"

AWateringCan::AWateringCan()
{
	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

void AWateringCan::BeginPlay()
{
	Super::BeginPlay();
	start_loc = GetActorLocation();
}

void AWateringCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWateringCan::ReturnToPoint()
{
	SetActorLocation(start_loc);
}
