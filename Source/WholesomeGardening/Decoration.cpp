// Fill out your copyright notice in the Description page of Project Settings.


#include "Decoration.h"

ADecoration::ADecoration()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void ADecoration::BeginPlay()
{
	Super::BeginPlay();
}

void ADecoration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADecoration::PopulateObject(FPlaceableObjData new_obj_data)
{
	obj_data = new_obj_data;
}
