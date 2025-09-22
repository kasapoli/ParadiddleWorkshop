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


DECLARE_DELEGATE_RetVal_TwoParams(AActor*,FDrumSpawnRequestDelegate, UClass* ,FVector);
DECLARE_DELEGATE_RetVal_OneParam(AActor*, FModDrumGetRequestDelegate, AActor*);
DECLARE_DELEGATE_RetVal_OneParam(FLinearColor, FDrumColorRequestDelegate, EModDrumType);
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

	/**  Call this  to spawn a mod drum, spawning and registering to Communication Subsystem will be handled by the main app
	*
	*  @return Returns the spawned drum actor based on the drum actor class defined in the main app. DO NOT cast to
	*  your custom class.
	*/
	UFUNCTION(BlueprintCallable, Category = "ModDrums")
	AActor* SpawnModDrum(UClass* DrumClass, FVector SpawnPos);

	/**  Call this  to get the actor spawned from mod class. This can be cast to the mod drum class.
	* 
	*  MainAppDrumActor: Drum Actor spawned by the main application.
	*  @return Returns the mod drum adtor associated with the main app actor.
	*  
	*/
	UFUNCTION(BlueprintCallable, Category = "ModDrums")
	AActor* GetModDrum(AActor* MainAppDrumActor);

	/**  Call this  to get the map of all currently active drums
	* 
	*  @return This map contains references to all the active drum actors in the app
	* The referenced actors are based on classes that belong to the main app.
	* DrumHit Delegate will be broadcasted referring to these actors.
	* Values of the map contain information on Drum Type and Color
	* Use GetModDrum function with these actors to access your custom classes
	* DO NOT MODIFY - HANDLED BY THE MAIN APP
	*/
	UFUNCTION(BlueprintCallable)
	const TMap<AActor*, FActiveDrumData>& GetActiveDrums() {return ActiveDrums;};

	/**  Call this function to get the  color used by the main app for the given drum type. Using matching colors
	 *  is recommended but not compulsory
	* 
	*  @return color for the drum type
	*/
	UFUNCTION(BlueprintCallable)
	FLinearColor GetModDrumColor(EModDrumType ModDrumType);

	
	/**  DO NOT CALL-HANDLED BY MAIN APP
	*/
	UFUNCTION(BlueprintCallable)
	void AddActiveDrumForMod(AActor* DrumActor, FActiveDrumData DrumData) {ActiveDrums.Add(DrumActor, DrumData);};

	/**  DO NOT CALL-HANDLED BY MAIN APP
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveActiveDrumForMod(AActor* DrumActor){ActiveDrums.Remove(DrumActor);};
	
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

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FDrumSpawnRequestDelegate ModSpawnRequestDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FModDrumGetRequestDelegate ModDrumGetRequestDelegate;
	
	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FDrumColorRequestDelegate DrumColorRequestDelegate;
	
private:

	/**  This map contains references to all the active drum actors in the app
	* The referenced actors are based on classes that belong to the main app.
	* DrumHit Delegate will be broadcasted referring to these actors.
	* Values of the map contain information on Drum Type and Color
	* Use GetModDrum function with these actors to access your custom classes
	*
	* DO NOT MODIFY - HANDLED BY THE MAIN APP
	*/
	UPROPERTY()
	TMap<AActor*, FActiveDrumData> ActiveDrums;
};
