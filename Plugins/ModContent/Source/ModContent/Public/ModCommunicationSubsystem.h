// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ModDataTypes.h"
#include "ModCommunicationSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FModDrumHit,const FModDrumHitStruct&,DrumHitData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDrumCreated, AActor*, DrumActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDrumRemoved, AActor*, DrumActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSongCreated, FString, SongName, FString, Artist, float, SongLength, FString, Difficulty );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSongFinished,const FModSongResultData&, SongResultData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSongDeleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFireModeSwitched, bool, IsFireModeOn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSongTimeReset, float, NewSongTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSongPauseSwitch,bool,IsPaused);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSongNoteHit, bool, IsNoteMissed);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FModMapLoadCalled,const TSoftObjectPtr<UWorld>&, ModMap);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelStreamCompleteDelegate,bool,IsSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelUnloadCompleteDelegate,bool,IsSuccess);
/**
 * 
 */
UCLASS()
class MODCONTENT_API UModCommunicationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	//FUNCTIONS, VARIABLES AND DELEGATES TO BE USED BY MODDERS
	UFUNCTION(BlueprintCallable)
	FRealtimeSongData GetCurrentSongData();

	UFUNCTION(BlueprintCallable)
	void LoadModMap(const TSoftObjectPtr<UWorld> MapToLoad);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FModDrumHit DrumHit;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDrumCreated DrumCreated;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDrumRemoved DrumRemoved;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongCreated SongCreated;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongFinished SongFinished;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongDeleted SongDeleted;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FFireModeSwitched FireModeSwitched;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongTimeReset SongTimeReset;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongPauseSwitch SongPauseSwitch;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongNoteHit SongNoteHit;

	//MAIN GAME FUNCTIONS VARIABLES AND DELEGATES

	UPROPERTY(BlueprintReadWrite)
	FRealtimeSongData RealtimeSongData;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FModMapLoadCalled ModMapLoadCalled;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FLevelStreamCompleteDelegate LevelStreamCompleteDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FLevelUnloadCompleteDelegate LevelUnloadCompleteDelegate;


};
