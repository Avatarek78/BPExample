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

    /** 
    * Print text to log as FATAL Always prints a fatal error to console (and log file) and crashes (even if logging is disabled). 
    * !!! BEWARE OF USING THIS METHOD, BECAUSE IT TRULY CAUSES CRASH NOT ONLY GAME BUT ALSO WHOLE UNREAL ENGINE !!!
    * For details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine 
    */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogFatal(const FString& message);

    /** Print text to log as INFO. Prints a message to a log file (does not print to console). For details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void Log(const FString& message);

    /** Print text to log as warning, for details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogWarn(const FString& message);

    /** Print text to log as error, for details see: https://dev.epicgames.com/documentation/en-us/unreal-engine/logging-in-unreal-engine */
    UFUNCTION(BlueprintCallable, Category = "PluginExample")
    void LogErr(const FString& message);
	
};
