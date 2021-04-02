// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "CoinSpawner.h"
#include "GardeningData.h"
#include "Plant.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDirtDespawn);

UCLASS()
class WHOLESOMEGARDENING_API APlant : public AItemBase
{
	GENERATED_BODY()

public:
	APlant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* st_mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FPlantData plant_data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EGrowthStage current_growth_stage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	TSubclassOf<ACoinSpawner> coin_spawner_class;

	UPROPERTY()
	FTimerHandle growth_timer;

	//Init
	UFUNCTION(BlueprintCallable)
	void InitPlant(FPlantData new_data);

	//Growth
	UFUNCTION(BlueprintCallable)
	void StartGrowth();
	UFUNCTION(BlueprintCallable)
	void StopGrowth() { is_watered = false; }
	UFUNCTION()
	void SetDuration(float _duration) { current_duration = _duration; }
	UFUNCTION()
	void ReachNewStage();

	UPROPERTY(BlueprintAssignable)
	FOnSmokeBurst OnSmokeBurst;
	UPROPERTY(BlueprintAssignable)
	FOnTimerSpawn OnTimerSpawn;
	UPROPERTY(BlueprintAssignable)
	FOnResourceExtract OnResourceExtract;
	UPROPERTY(BlueprintAssignable)
	FOnDirtDespawn OnDirtDespawn;
	
	UFUNCTION(BlueprintCallable)
	int ExtractResources();

	//Getters
	UFUNCTION(BlueprintCallable)
	bool IsWatered() { return is_watered; }
	UFUNCTION(BlueprintCallable)
	float GetCurrentDuration() { return current_duration; }
	UFUNCTION(BlueprintCallable)
	float GetCurrentDurationPercentage() { return current_duration / plant_data.plant_duration; }
	UFUNCTION(BlueprintCallable)
	bool IsReadyToExtract() { return ready_to_extract; }
	
	//Setters
	UFUNCTION()
	void SetReadyToExtract(bool val) { ready_to_extract = val; }

	UFUNCTION()
	void SpawnCoins(int resources);

private:
	bool is_watered = false;
	bool ready_to_extract;
	float current_duration = 0.0f;
};
