// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshCOmponent.h"
#include "GardeningData.h"
#include "Hoe.generated.h"

UCLASS()
class WHOLESOMEGARDENING_API AHoe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHoe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FItemData item_data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Offset")
	FVector offset;

	UPROPERTY()
	FVector start_loc;
	UPROPERTY()
	ESoilType target_soil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float hoe_time;

	UPROPERTY(BlueprintReadWrite)
	bool is_using;
	
	UFUNCTION(BlueprintCallable)
	void SetSoil(ESoilType new_soil) { target_soil = new_soil;  }

	UFUNCTION(BlueprintCallable)
	void TeleportToPoint(FVector point);
	UFUNCTION(BlueprintCallable)
	void ReturnToPoint();
	UFUNCTION(BlueprintCallable)
	bool IsUsing();
};
