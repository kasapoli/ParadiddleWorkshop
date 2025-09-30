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
DECLARE_DELEGATE_RetVal(ECollisionChannel,FInterfaceLaserChannelRequestDelegate);
DECLARE_DELEGATE_OneParam(FRequestManipulationModeSwitchDelegate,bool);
DECLARE_DELEGATE_RetVal_OneParam(bool,FHighwayTrackOverrideSetDelegate,UClass*);
DECLARE_DELEGATE(FDisableHighwayTrackOverride);
DECLARE_DELEGATE_RetVal_TwoParams(bool,FHighwayNoteOverrideSetDelegate,UClass*,UClass*);
DECLARE_DELEGATE(FDisableHighwayNoteOverride);
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

	/**  Call this function to get the collision channel of the UI interaction laser to set response
	 *  Main app will try to access PDModInteractionInterface functions once collision has been triggered
	* 
	*  @return Collision channel of the UI Interaction laser used in the main app
	*/
	UFUNCTION(BlueprintCallable)
	ECollisionChannel RequestLaserInteractionChannel();
	
	/**  Call this function to set the class to override the highway track
	 *  Beware that this class should be a child class of PDMHighwayTrackOverride class
	 *
	 *  @return returns true if override is successful, override will fail if track has already
	 *  been overridden
	*/
	UFUNCTION(BlueprintCallable)
	bool SetHighwayTrackOverrideClass(UClass* TrackOverrideClass);

	/**  Call this function to set the class to override the highway notes
	*  Beware that this class should be a child class of PDMHighwayNoteOverride class
	*	If you wish to override only one class, you can pass nullptr as an argument for the other.
	*	
	*  @return returns true if override is successful, override will fail if any one of the notes has already
	*  been overridden
	*/
	UFUNCTION(BlueprintCallable)
	bool SetHighwayNoteOverrideClasses(UClass* CircleNoteOverride , UClass* RectangleClassOverride);

	/**  Call this function to disable Highway Track override
	*  
	*/
	UFUNCTION(BlueprintCallable)
	void DisableHighwayTrackOverride();
	
	/**  Call this function to disable Highway Noteoverride
    *  
    */
	UFUNCTION(BlueprintCallable)
	void DisableHighwayNoteOverride();

	/**  Call this function to switch between play mode and manipulation mdoe
	*  Play Mode refers to player having drumsticks in hands and manipulation mode
	*  is the state in which player has controllers to manipulate the environment
	*/
	UFUNCTION(BlueprintCallable)
	void RequestManipulationModeSwitch(bool IsManipulationModeOn);
	
	/**  DO NOT CALL-HANDLED BY MAIN APP
	*/
	UFUNCTION(BlueprintCallable)
	void AddActiveDrumForMod(AActor* DrumActor, FActiveDrumData DrumData) {ActiveDrums.Add(DrumActor, DrumData);};

	/**  DO NOT CALL-HANDLED BY MAIN APP
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveActiveDrumForMod(AActor* DrumActor){ActiveDrums.Remove(DrumActor);};
	

	/** Subscribe to this to listen to drum hits including hits from the drums that does not belong to your mod. 
	 *	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app both for mod and non-mod drums
	 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FModDrumHit DrumHit;
	
	/** Broadcasted when a new drum is introduced to the scene. 
	 *	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app both for mod and non-mod drums
	 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDrumCreated DrumCreated;
	
	/** Broadcasted when a drum is removed from the scene
	 *	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app both for mod and non-mod drums
	 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDrumRemoved DrumRemoved;

	/** Broadcasted when a song gets created
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongCreated SongCreated;
	
	/** Broadcasted when a song is completed (not deleted)
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongFinished SongFinished;

	/** Broadcasted when a song is deleted (it may not be completed)
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongDeleted SongDeleted;

	/** Broadcasted when fire mode is enabled/dieabled due the consecutive successful hits or a miss
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FFireModeSwitched FireModeSwitched;
	
	/** Broadcasted when the song time is reset due to an event such as rewind, fast-forward etc.
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongTimeReset SongTimeReset;

	/** Broadcasted when the song time is reset due to an event such as rewind, fast-forward etc.
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSongPauseSwitch SongPauseSwitch;

	/** Broadcasted when a song note has completed its lifetime, either by being hit successfully or by
	 * being missed
	*	ONLY SUBSCRIBE, DO NOT BROADCAST - Only called from the main app 
	*/
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

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FInterfaceLaserChannelRequestDelegate InterfaceLaserChannelRequestDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FHighwayTrackOverrideSetDelegate HighwayTrackOverrideSetDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FDisableHighwayTrackOverride DisableHighwayTrackOverrideDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FRequestManipulationModeSwitchDelegate RequestManipulationModeSwitchDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FHighwayNoteOverrideSetDelegate HighwayNoteOverrideSetDelegate;

	/**  This delegate is used to communicate with the main app package by the main app
	*  DO NOT BIND OR CALL MANUALLY
	*/
	FDisableHighwayNoteOverride DisableHighwayNoteOverrideDelegate;
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
