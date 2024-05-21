Yes, you can set an instance of a class into a static variable in C++ and then use it as a target for your methods in Unreal Engine. This approach can be useful for singleton patterns or globally accessible instances. Here’s how you can do it:

### Step-by-Step Guide

1. **Define a Static Variable in Your Class**:
   - Create a static pointer variable in your class to hold the instance.

2. **Implement a Method to Set and Get the Static Instance**:
   - Provide functions to set and retrieve the static instance.

3. **Use the Static Instance in Blueprint**:
   - Expose a function to Blueprint to get the static instance so it can be used as a target.

### Example Code

#### Define a Static Variable

1. **Create the Header File** (`MySingletonClass.h`)

```cpp
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MySingletonClass.generated.h"

UCLASS(Blueprintable)
class YOURPROJECT_API UMySingletonClass : public UObject
{
    GENERATED_BODY()

private:
    // Static instance
    static UMySingletonClass* Instance;

public:
    // Constructor
    UMySingletonClass();

    // Function to initialize the instance
    UFUNCTION(BlueprintCallable, Category = "Singleton")
    static void InitializeSingleton();

    // Function to get the instance
    UFUNCTION(BlueprintCallable, Category = "Singleton")
    static UMySingletonClass* GetInstance();

    // Your custom method
    UFUNCTION(BlueprintCallable, Category = "Singleton")
    void MyCustomMethod();
};
```

2. **Implement the Functions** (`MySingletonClass.cpp`)

```cpp
#include "MySingletonClass.h"

// Initialize the static instance to nullptr
UMySingletonClass* UMySingletonClass::Instance = nullptr;

UMySingletonClass::UMySingletonClass()
{
    // Constructor logic if needed
}

void UMySingletonClass::InitializeSingleton()
{
    if (Instance == nullptr)
    {
        Instance = NewObject<UMySingletonClass>();
        Instance->AddToRoot(); // Prevent garbage collection
    }
}

UMySingletonClass* UMySingletonClass::GetInstance()
{
    if (Instance == nullptr)
    {
        InitializeSingleton();
    }
    return Instance;
}

void UMySingletonClass::MyCustomMethod()
{
    // Custom method logic
    UE_LOG(LogTemp, Warning, TEXT("MyCustomMethod called on Singleton instance"));
}
```

### Using the Singleton in Blueprint

1. **Compile Your Project**:
   - Ensure that you compile your project so the new class and functions are available in the Blueprint editor.

2. **Initialize the Singleton**:
   - In your game initialization code (e.g., GameMode, PlayerController, or any other suitable place), call `UMySingletonClass::InitializeSingleton()` to ensure the singleton instance is created.

   ```cpp
   // Example in GameMode
   void AMyGameMode::BeginPlay()
   {
       Super::BeginPlay();
       UMySingletonClass::InitializeSingleton();
   }
   ```

3. **Access the Singleton in Blueprint**:
   - In the Blueprint editor, you can call `GetInstance` to get the singleton instance and then call `MyCustomMethod` on it.

### Example Blueprint Usage

1. **Get Singleton Instance**:
   - Drag off from an event node (like Event BeginPlay) and call `GetInstance` from `UMySingletonClass`.

2. **Call Custom Method**:
   - Use the returned instance to call `MyCustomMethod`.

### Summary

By defining a static variable in your class and providing functions to initialize and get the instance, you can create a singleton pattern in Unreal Engine. This instance can be accessed in both C++ and Blueprints, allowing you to use it as a target for your methods. This approach is particularly useful for managing global state or providing globally accessible functionality within your Unreal Engine project.