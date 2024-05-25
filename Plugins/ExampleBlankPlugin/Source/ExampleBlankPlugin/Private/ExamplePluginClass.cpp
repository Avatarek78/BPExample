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
        * "Prevent garbage collection" This sometimes leads to this ERROR in UE!:
        * LogOutputDevice: Error: === Handled ensure: ===
        * LogOutputDevice: Error: Ensure condition failed: bIsValidObjectReference  [File:D:\build\++UE5\Sync\Engine\Source\Runtime\Engine\Private\BlueprintGeneratedClass.cpp] [Line: 2370] 
        * LogOutputDevice: Error: Invalid object referenced by the PersistentFrame: 0x000009773a4ba8c0 (Blueprint object: Blueprint /Game/FirstPerson/Blueprints/BP_FirstPersonPlayerController.BP_FirstPersonPlayerController, ReferencingProperty: ObjectProperty /Game/FirstPerson/Blueprints/BP_FirstPersonPlayerController.BP_FirstPersonPlayerController_C:ExecuteUbergraph_BP_FirstPersonPlayerController:CallFunc_getExamplePluginClass_ReturnValue, Instance: BP_FirstPersonPlayerController_C /Game/FirstPerson/Maps/UEDPIE_0_FirstPersonMap.FirstPersonMap:PersistentLevel.BP_FirstPersonPlayerController_C_0, Address:
        *  0x000009773e217bf8) - If you have a reliable repro for this, please contact the development team with it.
        * LogOutputDevice: Error: Stack: 
        * LogOutputDevice: Error: [Callstack] 0x00007fff8bd7b572 UnrealEditor-Engine.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff898dfcbf UnrealEditor-Engine.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95e0e574 UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95e13b2c UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff898a063d UnrealEditor-Engine.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95b48901 UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95aa2963 UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95b04a88 UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95a971ee UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff95a39944 UnrealEditor-CoreUObject.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff93472485 UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff934721bf UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff9349a115 UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff93462390 UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff93666b13 UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff93acb7ad UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007fff93abf127 UnrealEditor-Core.dll!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007ff8daf87344 KERNEL32.DLL!UnknownFunction []
        * LogOutputDevice: Error: [Callstack] 0x00007ff8db1226b1 ntdll.dll!UnknownFunction []
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

