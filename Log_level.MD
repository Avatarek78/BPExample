To create a C++ class that allows passing an `ELogLevel` argument for printing to the log in Unreal Engine, you can follow these steps:

1. **Define the ELogLevel Enumeration**: Define the `ELogLevel` enumeration that represents different log levels (e.g., INFO, WARNING, ERROR).

2. **Create the Log Printing Function**: Create a function that accepts a log message and an `ELogLevel` parameter, and prints the message to the log based on the specified log level.

3. **Include Necessary Headers**: Ensure that you include the necessary headers for using `UE_LOG` and other Unreal Engine functionalities.

Here's an example implementation:

```cpp
#pragma once

#include "CoreMinimal.h"
#include "LoggingClass.generated.h"

UENUM(BlueprintType)
enum class ELogLevel : uint8
{
    INFO UMETA(DisplayName = "Info"),
    WARNING UMETA(DisplayName = "Warning"),
    ERROR UMETA(DisplayName = "Error")
};

UCLASS()
class MYPROJECT_API ULoggingClass : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Logging")
    static void Log(const FString& Message, ELogLevel LogLevel);
};
```

```cpp
#include "LoggingClass.h"
#include "Engine/Engine.h"

void ULoggingClass::Log(const FString& Message, ELogLevel LogLevel)
{
    switch (LogLevel)
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
```

In this implementation:

- The `ELogLevel` enumeration represents different log levels.
- The `ULoggingClass` class contains a static function `Log` that accepts a log message and an `ELogLevel` parameter. It uses `UE_LOG` to print the message to the log based on the specified log level.

You can then use this `ULoggingClass::Log` function in your Unreal Engine project to log messages with different log levels. For example:

```cpp
ULoggingClass::Log(TEXT("This is an info message."), ELogLevel::INFO);
ULoggingClass::Log(TEXT("This is a warning message."), ELogLevel::WARNING);
ULoggingClass::Log(TEXT("This is an error message."), ELogLevel::ERROR);
```

This will print the messages to the output log in the Unreal Editor with the appropriate log level.

### Podrobnejsi enum

The second argument of the `UE_LOG` macro in Unreal Engine is a verbosity level specifier. It determines the severity or importance of the log message. This argument is of type `ELogVerbosity`.

The `ELogVerbosity` enum is defined in the `LogCategory.h` header file in the Unreal Engine source code. It contains several enumeration values representing different levels of verbosity, such as `Log`, `Warning`, `Error`, `Display`, `Fatal`, etc.

Here's a simplified version of the `ELogVerbosity` enum:

```cpp
UENUM(BlueprintType)
enum class ELogVerbosity : uint8
{
    NoLogging = 0,
    Fatal,
    Error,
    Warning,
    Display,
    Log,
    Verbose,
    VeryVerbose,
};
```

When using `UE_LOG`, you specify one of these verbosity levels as the second argument to indicate the severity of the log message. For example:

```cpp
UE_LOG(LogTemp, Warning, TEXT("This is a warning message"));
```

In this example, `Warning` is the second argument, indicating that the message should be logged with a warning level of verbosity.

When you create your own logging functions in Unreal Engine, you can follow the same pattern and accept a parameter of type `ELogVerbosity` to specify the verbosity level of the log message.