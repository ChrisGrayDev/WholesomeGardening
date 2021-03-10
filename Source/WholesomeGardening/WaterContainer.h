// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "WaterExtractable.h"
#include "GardeningData.h"
#include "WaterContainer.generated.h"

UCLASS()
class WHOLESOMEGARDENING_API AWaterContainer : public AActor, public IWaterExtractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaterContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	bool is_container_infinite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	int max_number_of_charges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	int current_number_of_charges;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FItemData item_data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float extraction_time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float fill_time;
	UPROPERTY(BlueprintReadWrite)
	bool is_extracting;
	UPROPERTY(BlueprintReadWrite)
	bool is_refilling;

	UPROPERTY()
	FTimerHandle extract_timer;

	UFUNCTION()
	void Extract();
	UFUNCTION()
	void Refill();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool IsEmpty();
	virtual bool IsEmpty_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool IsFull();
	virtual bool IsFull_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ExtractOneCharge();
	virtual void ExtractOneCharge_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TeleportToPoint(FVector point);
	virtual void TeleportToPoint_Implementation(FVector point);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool IsFinishedExtracting();
	virtual bool IsFinishedExtracting_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RefillOneCharge();
	virtual void RefillOneCharge_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool IsFinishedRecharging();
	virtual bool IsFinishedRecharging_Implementation();
};
