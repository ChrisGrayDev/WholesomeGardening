// Fill out your copyright notice in the Description page of Project Settings.


#include "AmbientSoundTrigger.h"

// Sets default values
AAmbientSoundTrigger::AAmbientSoundTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	audio_comp = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio comp"));
}

// Called when the game starts or when spawned
void AAmbientSoundTrigger::BeginPlay()
{
	Super::BeginPlay();
	audio_comp->SetVolumeMultiplier(volume_mod);
	StartLoop();
}

// Called every frame
void AAmbientSoundTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmbientSoundTrigger::StartLoop()
{
	if (ambient_sound != nullptr)
		audio_comp->SetSound(ambient_sound);

	audio_comp->Play(0.0f);
}

