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

ECollisionChannel UModCommunicationSubsystem::RequestLaserInteractionChannel()
{
	if (InterfaceLaserChannelRequestDelegate.IsBound())
	{
		return InterfaceLaserChannelRequestDelegate.Execute();
	}
	return ECollisionChannel::ECC_WorldDynamic;
}

bool UModCommunicationSubsystem::SetHighwayTrackOverrideClass(UClass* TrackOverrideClass, UClass* KickTrackOverrideClass)
{
	if (HighwayTrackOverrideSetDelegate.IsBound())
	{
		return HighwayTrackOverrideSetDelegate.Execute(TrackOverrideClass, KickTrackOverrideClass);
	}
	return false;
}

bool UModCommunicationSubsystem::SetHighwayNoteOverrideClasses(UClass* CircleNoteOverride,
	UClass* RectangleClassOverride, UClass* KickNoteOverrideClass)
{
	if (HighwayNoteOverrideSetDelegate.IsBound())
	{
		return HighwayNoteOverrideSetDelegate.Execute(CircleNoteOverride, RectangleClassOverride ,KickNoteOverrideClass);
	}
	return false;
}

UClass* UModCommunicationSubsystem::GetHighwayTrackOverrideClass(EModTrackType TrackType)
{
	if (GetTrackOverrideDelegate.IsBound())
	{
		return GetTrackOverrideDelegate.Execute(TrackType);
	}
	return nullptr;
}

UClass* UModCommunicationSubsystem::GetHighwayNoteOverrideClass(EModNoteType NoteType)
{
	if (GetNoteOverrideDelegate.IsBound())
	{
		return GetNoteOverrideDelegate.Execute(NoteType);
	}
	return nullptr;
}

void UModCommunicationSubsystem::DisableHighwayTrackOverride()
{
	if (DisableHighwayTrackOverrideDelegate.IsBound())
	{
		DisableHighwayTrackOverrideDelegate.Execute();
	}
}

void UModCommunicationSubsystem::DisableHighwayNoteOverride()
{
	if (DisableHighwayNoteOverrideDelegate.IsBound())
	{
		DisableHighwayNoteOverrideDelegate.Execute();
	}
}

void UModCommunicationSubsystem::RequestManipulationModeSwitch(bool IsManipulationModeOn)
{
	if (RequestManipulationModeSwitchDelegate.IsBound())
	{
		RequestManipulationModeSwitchDelegate.Execute(IsManipulationModeOn);
	}
}


