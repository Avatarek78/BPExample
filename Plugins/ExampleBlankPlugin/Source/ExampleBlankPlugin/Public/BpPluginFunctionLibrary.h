// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ExamplePluginClass.h"
#include "BpPluginFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEBLANKPLUGIN_API UBpPluginFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Get instance of UExamplePluginClass which is singleton (one instance created only first time) */
	UFUNCTION(BlueprintCallable, Category = "PluginExample")
	static UExamplePluginClass* getExamplePluginClass();
	
};
