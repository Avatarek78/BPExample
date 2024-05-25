// Fill out your copyright notice in the Description page of Project Settings.


#include "ExamplePluginClass.h"

UExamplePluginClass* UExamplePluginClass::instance = nullptr;

UExamplePluginClass::UExamplePluginClass()
{
    // Constructor logic (if any)
}

/**
* Get instance of this singleton class. 
*/
UExamplePluginClass* UExamplePluginClass::getInstance() {
    if (instance == nullptr) {
        instance = NewObject<UExamplePluginClass>();
        /**
        * "Prevent garbage collection" This earlier leads to this ERROR in UE!: 
        * Error: Invalid object referenced by the PersistentFrame: 0x000009773a4ba8c0 (Blueprint object: Blueprint /Game/FirstPerson/...
        * Now seems OK
        */
        instance->AddToRoot(); // Prevent garbage collection
        Log("New instance of UExamplePluginClass created.", ELogLevel::INFO);
    }
    else {
        Log("Existing instance of UExamplePluginClass returned.", ELogLevel::INFO);
    }
    return instance;
}

void UExamplePluginClass::Log(const FString& Message, ELogLevel eLogLevel)
{
    switch (eLogLevel)
    {
    case ELogLevel::INFO:
        UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
        break;
    case ELogLevel::WARNING:
        UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
        break;
    case ELogLevel::ERROR:
        UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
        break;
    default:
        UE_LOG(LogTemp, Log, TEXT("%s (Unknown LogLevel)"), *Message);
        break;
    }
}

void UExamplePluginClass::ExampleFunction()
{
    GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Magenta, "** UExamplePluginClass::ExampleFunction() 4");
}

void UExamplePluginClass::LogFatal(const FString& message)
{
    UE_LOG(LogTemp, Fatal, TEXT("%s"), *message);
}

void UExamplePluginClass::LogInfo(const FString& message)
{
    UE_LOG(LogTemp, Log, TEXT("%s"), *message);
}

void UExamplePluginClass::LogWarn(const FString& message)
{
    UE_LOG(LogTemp, Warning, TEXT("%s"), *message);
}

void UExamplePluginClass::LogErr(const FString& message)
{
    UE_LOG(LogTemp, Error, TEXT("%s"), *message);
}

