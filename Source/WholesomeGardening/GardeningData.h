// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "GardeningData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSmokeBurst);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerSpawn, float, TimeToFinish);

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
	Plant			UMETA(DisplayName = "Plant"),
	Object			UMETA(DisplayName = "Object"),
	WaterContainer	UMETA(DisplayName = "Water container")
};

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Fruit		UMETA(DisplayName = "Fruit"),
	Vegetable	UMETA(DisplayName = "Vegetable"),
	Seed		UMETA(DisplayName = "Seed"),
	Soil		UMETA(DisplayName = "Soil"),
	Flower		UMETA(DisplayName = "Flower"),
	Decoration	UMETA(DisplayName = "Decoration")
};

UENUM(BlueprintType)
enum class ESunlightType : uint8
{
	Sunny		UMETA(DisplayName = "Sunny"),
	Shade		UMETA(DisplayName = "Shade")
};

UENUM(BlueprintType)
enum class EGrowthStage : uint8
{
	Sapling		UMETA(DisplayName = "Sapling"),
	Medium		UMETA(DisplayName = "Medium"),
	Grown		UMETA(DisplayName = "Grown")
};

USTRUCT(BlueprintType)
struct FSoilData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMesh* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESoilType soil_type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESunlightType sunlight_type;
};

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType item_type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemCategory item_category;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* icon;
};

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItemData item_data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int quantity;
};

USTRUCT(BlueprintType)
struct FPlaceableObjData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* meseh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int tile_size;
};

USTRUCT(BlueprintType)
struct FPlantData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> mesh_states;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESoilType compatible_soil;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESunlightType compatible_sunlight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int number_of_stages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float plant_duration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int tile_size;
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
