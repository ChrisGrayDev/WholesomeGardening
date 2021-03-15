// Fill out your copyright notice in the Description page of Project Settings.


#include "Hoe.h"

// Sets default values
AHoe::AHoe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hoe"));
}

// Called when the game starts or when spawned
void AHoe::BeginPlay()
{
	Super::BeginPlay();
	start_loc = GetActorLocation();
}

// Called every frame
void AHoe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHoe::TeleportToPoint(FVector point)
{
	SetActorLocation(point + offset);
}

void AHoe::ReturnToPoint()
{
	SetActorLocation(start_loc);
}

bool AHoe::IsUsing()
{
	return is_using;
}

