// Fill out your copyright notice in the Description page of Project Settings.


#include "PluginActor.h"

// Sets default values
APluginActor::APluginActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APluginActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APluginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

