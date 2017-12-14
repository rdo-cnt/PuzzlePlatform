// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UPuzzlePlatformGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer);
	//Init or construct?
	void Init();
	
	UFUNCTION(Exec)
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& a);
	
	//Exec Compatible classes
		//Playercontrollers(change size, other variables)
		//Possesed pawns
		//HUDs
		//Cheat Managers
		//Game modes
		//Game instances

};
