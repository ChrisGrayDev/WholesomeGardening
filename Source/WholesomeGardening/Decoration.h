// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Decoration.generated.h"

/**
 * 
 */
UCLASS()
class WHOLESOMEGARDENING_API ADecoration : public AItemBase
{
	GENERATED_BODY()

public:
	ADecoration();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object data")
	FPlaceableObjData obj_data;

	UFUNCTION(BlueprintCallable)
	void PopulateObject(FPlaceableObjData new_obj_data);
};
