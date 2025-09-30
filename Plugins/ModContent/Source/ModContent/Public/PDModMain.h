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
	TArray<FModWorldData> ModWorldData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ModGames")
	TArray<FModWorldData> ModGamesData;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override")
	TArray<UClass*> HighwayTrackOverrideClasses;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override")
	TArray<UClass*> RectangleNoteClasses;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Highway Override")
	TArray<UClass*> CircleNoteClasses;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Drums")
	TArray<UClass*> CustomDrumClasses;
	
};
