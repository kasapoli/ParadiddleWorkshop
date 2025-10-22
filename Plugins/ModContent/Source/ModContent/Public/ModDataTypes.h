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
enum class  EModNoteType : uint8
{
	Circle,
	Rectangle,
	Kick
};

UENUM(BlueprintType)
enum class EModTrackType : uint8
{
	Default,
	Kick
};

UENUM(BlueprintType)
enum class ESoundAsset:uint8
{
	//SMM Kit
	SMM_China15,
	SMM_Crash13,
	SMM_Crash15,
	SMM_Crash16,
	SMM_Crash17,
	SMM_Ride17_Main,
	SMM_Ride17_Bell,
	SMM_Ride20_Main,
	SMM_Ride20_Bell,
	SMM_Tom1,
	SMM_Tom2,
	SMM_Tom3,
	SMM_Hihat_Open,
	SMM_Hihat_Close,

	
	//Aasi Kit
	Aasi_China8,
	Aasi_China10,
	Aasi_China18,
	Aasi_Crash_High,
	Aasi_Crash_Low,
	Aasi_Hihat_Open,
	Aasi_Hihat_Close,
	Aasi_Kick,
	Aasi_Ride_Bell,
	Aasi_Ride_Main,
	Aasi_Snare,
	Aasi_Snare_OffCenter,
	Aasi_Snare_Rim,
	Aasi_Tom1,
	Aasi_Tom3,

	//Crocell Kit
	Crocell_ChinaL,
	Crocell_ChinaR,
	Crocell_FloorTom1,
	Crocell_FloorTom2,
	Crocell_Hihat_Open,
	Crocell_Hihat_Close,
	Crocell_CrashL,
	Crocell_CrashR,
	Croceell_RackTom1,
	Croceell_RackTom2,
	Crocell_Ride_Main,
	Crocell_Ride_Bell,
	Crocell_Snare,

	//DRS_Kit
	DRS_Hihat_Open,
	DRS_Hihat_Close,
	DRS_Kick,
	DRS_Snare,
	DRS_Tom1,
	DRS_Tom2,
	DRS_Tom3,

	//Other instruments
	Bongo_High,
	Bongo_Low,
	Gong,
	Cowbell,
	Glockenspiel,
	Triangle,

	//No sound asset
	None,
	
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

USTRUCT(BlueprintType)
struct FHighwayOverrideData
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString FriendlyName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* CircleNoteOverride;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* RectangleNoteOverride;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* BeatNoteOverride;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* DefaultTrackOverride;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* KickNoteOverride;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UClass* KickTrackOverride;
};


/**
 * 
 */
UCLASS(BlueprintType)
class MODCONTENT_API UModDataTypes : public UObject
{
	GENERATED_BODY()
	
};
