// Fill out your copyright notice in the Description page of Project Settings.


#include "ModManagerActor.h"


// Sets default values
AModManagerActor::AModManagerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AModManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AModManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

