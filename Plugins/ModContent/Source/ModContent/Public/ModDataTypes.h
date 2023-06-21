// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FSkySphereData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor HorizonColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor ZenithColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor OverallColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor CloudColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SunHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CloudSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SunBrightness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CloudOpacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StarsBrightness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HorizonFalloff;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SunDeterminesLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UsesDirectionalLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector DirectionalLightPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator DirectionalLightRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor DirectionalLightColor;
	
};

USTRUCT(BlueprintType)
struct FSkyLightData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextureCube* CubeMapTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor LightColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Intensity;
	
};

USTRUCT(BlueprintType)
struct FModMapData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString MapName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* MapActorClass;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* MapIcon;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FSkySphereData MapSkySphereData;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FSkyLightData MapSkyLightData;
	
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


/**
 * 
 */
UCLASS(BlueprintType)
class MODCONTENT_API UModDataTypes : public UObject
{
	GENERATED_BODY()
	
};
