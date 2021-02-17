// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "AmbientSoundTrigger.generated.h"

UCLASS()
class WHOLESOMEGARDENING_API AAmbientSoundTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmbientSoundTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	UAudioComponent* audio_comp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundCue* ambient_sound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float volume_mod;

	UFUNCTION()
	void StartLoop();
};
