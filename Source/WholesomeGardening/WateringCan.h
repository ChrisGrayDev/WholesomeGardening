// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaterContainer.h"
#include "WateringCan.generated.h"

/**
 * 
 */
UCLASS()
class WHOLESOMEGARDENING_API AWateringCan : public AWaterContainer
{
	GENERATED_BODY()

public:

	AWateringCan();

protected:

	virtual void BeginPlay() override;

public: 

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float time_before_teleport;
	UPROPERTY()
	FTimerHandle teleport_timer;

	UFUNCTION(BlueprintCallable)
	void StartTeleportBack();
};
