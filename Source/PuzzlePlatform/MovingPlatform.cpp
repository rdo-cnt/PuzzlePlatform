// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    //enable ticking
    PrimaryActorTick.bCanEverTick = true;

    SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   if (ActiveTriggers > 0)
   {
	   //Actualize la posicion del cubo en el server, pero no la actualiza
	   if (HasAuthority())
	   {
		   FVector Location = GetActorLocation();
		   //Location += FVector(Speed * DeltaTime,0,0);
		   //Calculate direction 

		   float JourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();
		   float JourneyTraveled = (Location - GlobalStartLocation).Size();

		   if (JourneyTraveled > JourneyLenght)
		   {
			   FVector Temp = GlobalStartLocation;
			   GlobalStartLocation = GlobalTargetLocation;
			   GlobalTargetLocation = Temp;
		   }

		   FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		   Location += Speed * DeltaTime * Direction;
		   SetActorLocation(Location);
	   }
   }

    
   
   //Challenge: hacer que el cubo solo se actualize en el client
    // if(!HasAuthority())
    // {
    //     FVector Location = GetActorLocation(); 
    //     Location += FVector(Speed * DeltaTime,0,0);
    //     SetActorLocation(Location);
    // }
}

void AMovingPlatform::BeginPlay()
{
   Super::BeginPlay();
   //Hace que se actualize la posicion del cubo en el server, para clients
    if(HasAuthority())
        {
        SetReplicates(true);
        SetReplicateMovement(true);
        }

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
		ActiveTriggers--;
}

