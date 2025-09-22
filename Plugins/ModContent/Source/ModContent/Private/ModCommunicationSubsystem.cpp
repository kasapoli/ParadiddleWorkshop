// Fill out your copyright notice in the Description page of Project Settings.


#include "ModCommunicationSubsystem.h"

FRealtimeSongData UModCommunicationSubsystem::GetCurrentSongData()
{
	return RealtimeSongData;
	
}

void UModCommunicationSubsystem::LoadModMap(const TSoftObjectPtr<UWorld> MapToLoad)
{
	ModMapLoadCalled.Broadcast(MapToLoad);

}

AActor* UModCommunicationSubsystem::SpawnModDrum(UClass* DrumClass, FVector SpawnPos)
{
	if (ModSpawnRequestDelegate.IsBound())
	{
		return ModSpawnRequestDelegate.Execute(DrumClass, SpawnPos);
	}
	return nullptr;
}

AActor* UModCommunicationSubsystem::GetModDrum(AActor* MainAppDrumActor)
{
	if (ModDrumGetRequestDelegate.IsBound())
	{
		return ModDrumGetRequestDelegate.Execute(MainAppDrumActor);
	}
	return nullptr;
}

FLinearColor UModCommunicationSubsystem::GetModDrumColor(EModDrumType ModDrumType)
{
	if (DrumColorRequestDelegate.IsBound())
	{
		return DrumColorRequestDelegate.Execute(ModDrumType);
	}
	return FLinearColor::Red;
}

