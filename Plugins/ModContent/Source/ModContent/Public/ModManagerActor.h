// Fill out your copyright notice in the Description page of Project Settings.

//FOR MODDERS: DO NOT CHANGE ANYTHING IN THIS CLASS. INHERIT FROM IT TO USE IT AS A HOOK TO THE MAIN APP
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModDataTypes.h"
#include "ModManagerActor.generated.h"


class UPDModMain;


UCLASS()
class MODCONTENT_API AModManagerActor : public AActor
{

	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AModManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**  This function will be used by both the main app and the Mod to access Mod Data.
	 *  @return Returns the Mod Data struct that contains details on the mod content
	 */
	UFUNCTION(BlueprintPure, Category="MainAppOnly")
	UPDModMain* GetModData_FromMain() {return ModData;};

	/**  This function will be called by the main app once the Mod gets loaded.
	 *  Override it in your Mod Class to handle Mod initialization
	*/
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category = "MainAppOnly")
	void InitMod_FromMain(AActor* PawnActor, ECollisionChannel UICollisionChannel);

	/**  This function will be called by the main app before the mod gets disabled
	*  Override it in your Mod Class to handle Mod disabling
	*/
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category = "MainAppOnly")
	void DisableMod_FromMain();

	/** Set to true if the mod has UI elements such as menus that should be enabled/disabled. This variable will affect
	 * the way the main app assigns UI functionality for your mod
	 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Mod Features")
	bool bHasSwitchableUI = true;

	/**  This function will be called by the main app to switch mod UI active status
	*  Override it in your Mod Class to handle UI enabling/disabling
	*/
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category = "MainAppOnly")
	void SwitchModUIActiveStatus_FromMain();
	
private:
	UPROPERTY(EditAnywhere)
	UPDModMain* ModData;
};
