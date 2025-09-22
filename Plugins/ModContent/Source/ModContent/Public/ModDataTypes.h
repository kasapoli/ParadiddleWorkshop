// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FModWorldData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString WorldFriendlyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> WorldPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString WorldDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* WorldIcon;
	
};

USTRUCT(BlueprintType)
struct FRealtimeSongData
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentComboCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFireModeOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentSongTime;
};

USTRUCT(BlueprintType)
struct FModDrumHitStruct
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* HitDrumActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor HitDrumColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HitVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HitLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsRightHand;
};

USTRUCT(BlueprintType)
struct FModSongResultData
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Score;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxComboCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Accuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SongName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Difficulty;
	
};

UENUM(BlueprintType)
enum class EModDrumType:uint8
{
	Snare,
	China15,
	Crash13,
	Crash15,
	Crash17,
	FloorTom,
	TealTom,
	GreenTom,
	Kick,
	HiHat,
	Ride17,
	Ride20,
	Other,
};

UENUM(BlueprintType)
enum class ESoundAsset:uint8
{
	Bongo,
	Cowbell,
	Glockenspiel,
	Triangle,
	China15,
	Crash13,
	Crash15,
	Crash17,
	Snare,
	FloorTom,
	TealTom,
	GreenTom,
	Kick,
	Ride17,
	Ride20,
	HiHat,
	
};

USTRUCT(BlueprintType)
struct FModDrumData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ESoundAsset ModDrumSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EModDrumType ModDrumType;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FLinearColor DrumColor;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString FriendlyName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* ModDrumClass;
};

USTRUCT(BlueprintType)
struct FActiveDrumData
{
	GENERATED_BODY()
	public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FLinearColor DrumColor;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EModDrumType DrumType;
	
};


/**
 * 
 */
UCLASS(BlueprintType)
class MODCONTENT_API UModDataTypes : public UObject
{
	GENERATED_BODY()
	
};
