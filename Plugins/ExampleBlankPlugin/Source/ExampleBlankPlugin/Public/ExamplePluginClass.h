// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExamplePluginClass.generated.h"

/**
 * Main class with C++ examples for UE. BlueprintType that can be used as variable in UE.
 */
UCLASS(BlueprintType)
class UExamplePluginClass : public UObject
{
	GENERATED_BODY()    

private:
    // Static instance of this singleton.    
    static UExamplePluginClass* instance;

public:
    
    UExamplePluginClass();

    static UExamplePluginClass* getInstance();

    // Example property
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PluginExample")
    FString ExampleProperty;

    // Example function
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void ExampleFunction();

    /** Print text to log as info, for details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogInfo(const FString& message);

    /** Print text to log as warning, for details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogWarn(const FString& message);

    /** Print text to log as error, for details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogErr(const FString& message);
	
};
