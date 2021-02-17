// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "WaterExtractable.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	bool is_container_infinite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	int max_number_of_charges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	int current_number_of_charges;

	UFUNCTION(BlueprintImplementableEvent)
	bool IsEmpty();
	virtual bool IsEmpty_Implementation();
	UFUNCTION(BlueprintImplementableEvent)
	void ExtractOneCharge();
	virtual void ExtractOneCharge_Implementation();
};
