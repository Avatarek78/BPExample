### Unreal Engine Classes: AActor, APawn, ACharacter, and UActorComponent

In Unreal Engine, these classes serve as fundamental building blocks for game development. Each has a specific role and usage scenario.

#### 1. **AActor**

`AActor` is the base class for all objects that can be placed or spawned in a level. It's a fundamental building block in Unreal Engine for anything that needs to be part of the game world.

**Key Features:**
- Can be placed in the world or spawned dynamically at runtime.
- Supports a variety of components to define behavior and appearance.
- Has a transformation (location, rotation, scale).
- Lifecycle methods: `BeginPlay()`, `Tick()`, and `EndPlay()`.
- Can interact with other actors via collision and overlap events.

**Example Usage:**
- Static meshes, lights, cameras, trigger volumes.

**Example Code:**
```cpp
// MyActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()
    
public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};
```

```cpp
// MyActor.cpp
#include "MyActor.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
```

#### 2. **APawn**

`APawn` is a subclass of `AActor` and represents any physical entity that can be possessed and controlled by a player or AI.

**Key Features:**
- Can be possessed by a player controller or AI controller.
- Typically used for player characters, NPCs, and other entities that need to be controlled.
- Supports movement components for controlling movement.
- Lifecycle methods: `PossessedBy()`, `UnPossessed()`.

**Example Usage:**
- Player characters, vehicles, controlled characters.

**Example Code:**
```cpp
// MyPawn.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class MYPROJECT_API AMyPawn : public APawn
{
    GENERATED_BODY()
    
public:
    AMyPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
```

```cpp
// MyPawn.cpp
#include "MyPawn.h"

AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyPawn::BeginPlay()
{
    Super::BeginPlay();
}

void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
```

#### 3. **ACharacter**

`ACharacter` is a subclass of `APawn` that is specifically designed for humanoid characters. It includes a `UCapsuleComponent` for collision, a `UCharacterMovementComponent` for movement, and an optional `USkeletalMeshComponent` for the mesh.

**Key Features:**
- Built-in movement logic for walking, jumping, swimming, flying, etc.
- Supports skeletal mesh and animations.
- Advanced movement capabilities: crouching, sprinting, etc.

**Example Usage:**
- Player characters, NPCs, enemies.

**Example Code:**
```cpp
// MyCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()
    
public:
    AMyCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
```

```cpp
// MyCharacter.cpp
#include "MyCharacter.h"

AMyCharacter::AMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Bind input actions here
}
```

#### 4. **UActorComponent**

`UActorComponent` is a base class for components that define reusable behavior that can be added to `AActor` instances. Components allow for modular and reusable game functionality.

**Key Features:**
- Not a physical part of the world, but adds behavior or properties to actors.
- Can be attached to any actor.
- Supports enabling and disabling.

**Example Usage:**
- Health components, inventory systems, custom logic handlers.

**Example Code:**
```cpp
// MyActorComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UMyActorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UMyActorComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
```

```cpp
// MyActorComponent.cpp
#include "MyActorComponent.h"

UMyActorComponent::UMyActorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UMyActorComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
```

### Summary

- **AActor**: Base class for all actors in the game world.
- **APawn**: Inherits from `AActor`, represents controllable entities.
- **ACharacter**: Inherits from `APawn`, adds functionality for humanoid characters.
- **UActorComponent**: Adds modular, reusable behavior to actors without being a physical entity.

Each class serves a specific purpose and choosing the right one depends on the functionality and behavior you need in your game.
