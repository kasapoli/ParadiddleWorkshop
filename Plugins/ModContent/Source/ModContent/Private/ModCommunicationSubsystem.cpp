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
                                                               UClass* RectangleClassOverride,
                                                               UClass* KickNoteOverrideClass,
                                                               UClass* BeatNoteOverrideClass)
{
	if (HighwayNoteOverrideSetDelegate.IsBound())
	{
		return HighwayNoteOverrideSetDelegate.Execute(CircleNoteOverride, RectangleClassOverride ,KickNoteOverrideClass,BeatNoteOverrideClass);
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

AActor* UModCommunicationSubsystem::GetDrumActorOfTrack(AActor* TrackOverrideActor)
{
	if (GetDrumActorOfTrackDelegate.IsBound())
	{
		return GetDrumActorOfTrackDelegate.Execute(TrackOverrideActor);
	}
	return nullptr;
}

bool UModCommunicationSubsystem::SetStartPointOfTrackManually(AActor* TrackOverrideActor, const FTransform& StartPoint)
{
	if (SetTrackStartPointDelegate.IsBound())
	{
		return SetTrackStartPointDelegate.Execute(TrackOverrideActor, StartPoint);
	}
	return false;
}

bool UModCommunicationSubsystem::SetEndPointOfTrackManually(AActor* TrackOverrideActor, const FTransform& EndPoint)
{
	if (SetTrackEndPointDelegate.IsBound())
	{
		return SetTrackEndPointDelegate.Execute(TrackOverrideActor, EndPoint);
	}
	return false;
}

void UModCommunicationSubsystem::SetStickMeshOverride(UStaticMesh* Mesh,const FTransform& TransformRelativeToReferenceMesh)
{
	if (RequestStickMeshOverrideDelegate.IsBound())
	{
		RequestStickMeshOverrideDelegate.Execute(Mesh,TransformRelativeToReferenceMesh);
	}
}

void UModCommunicationSubsystem::SetStickMaterialOverride(UMaterialInterface* Material, int MaterialIndex)
{
	if (RequestStickMaterialOverrideDelegate.IsBound())
	{
		RequestStickMaterialOverrideDelegate.Execute(Material, MaterialIndex);
	}
}

void UModCommunicationSubsystem::ClearStickOverrides()
{
	if (DisableStickOverridesDelegate.IsBound())
	{
		DisableStickOverridesDelegate.Execute();
	}
}


