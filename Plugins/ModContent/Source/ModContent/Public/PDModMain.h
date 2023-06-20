// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ModDataTypes.h"
#include "PDModMain.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MODCONTENT_API UPDModMain : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ModMaps")
	TArray<FModMapData> MapDatas;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override")
	bool bOverridesHighwayTrack;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override", meta = (EditCondition = "bOverridesHighwayTrack"))
	UClass* HighwayTrackOverrideClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override")
	bool bOverridesHighwayNotes;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override", meta = (EditCondition = "bOverridesHighwayNotes"))
	UClass* RectangleNoteClas;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override", meta = (EditCondition = "bOverridesHighwayNotes"))
	UClass* CircleNoteClass;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Drums")
	bool bOverridesDrums;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Drums", meta = (EditCondition="bOverridesDrums"))
	UClass* DrumClass;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Drums")
	TArray<FModDrumData> CustomDrumClasses;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Drums")
	bool bOverridesDrumsticks;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Drums", meta=(EditCondition="bOverridesDrumsticks"))
	UClass* DrumStickOverrideClass;
	
		
};
