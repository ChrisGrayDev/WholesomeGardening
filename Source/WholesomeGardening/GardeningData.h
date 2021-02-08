// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "GardeningData.generated.h"

UENUM(BlueprintType)
enum class ESoilType : uint8
{
	Sandy		UMETA(DisplayName = "Sandy"),
	Silty		UMETA(DisplayName = "Silty"),
	Clay		UMETA(DisplayName = "Clay"),
	Peaty		UMETA(DisplayName = "Peaty"),
	Chalky		UMETA(DisplayName = "Chalky"),
	Loamy		UMETA(DisplayName = "Loamy")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Plant		UMETA(DisplayName = "Plant"),
	Object		UMETA(DisplayName = "Object")
};

UENUM(BlueprintType)
enum class ESunlightType : uint8
{
	Sunny		UMETA(DisplayName = "Sunny"),
	Shade		UMETA(DisplayName = "Shade")
};

USTRUCT(BlueprintType)
struct FSoilData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESoilType soil_type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESunlightType sunlight_type;
};

UCLASS()
class WHOLESOMEGARDENING_API AGardeningData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGardeningData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
