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
    //Actualize la posicion del cubo en el server, pero no la actualiza
    if(HasAuthority())
    {
        FVector Location = GetActorLocation(); 
        Location += FVector(Speed * DeltaTime,0,0);
        SetActorLocation(Location);
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

    


}

