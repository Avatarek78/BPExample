// Fill out your copyright notice in the Description page of Project Settings.


#include "BpPluginFunctionLibrary.h"

UExamplePluginClass* UBpPluginFunctionLibrary::getExamplePluginClass()
{
    return UExamplePluginClass::getInstance();
}
