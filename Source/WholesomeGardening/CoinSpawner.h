// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.h"
#include "CoinSpawner.generated.h"

UCLASS()
class WHOLESOMEGARDENING_API ACoinSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float spawn_rate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ACoin> coin_class; 
	UPROPERTY(BlueprintReadWrite)
	FVector spawn_point;
	UPROPERTY(BlueprintReadWrite)
	int number_to_spawn;

	UPROPERTY()
	FTimerHandle spawn_timer;

	UFUNCTION(BlueprintCallable)
	void InitCoins(FVector loc, int number_of_coins);
	UFUNCTION()
	void SpawnNewCoin();

private:
	UPROPERTY()
	int number_spawned = 0;

};
