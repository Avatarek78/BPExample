// Fill out your copyright notice in the Description page of Project Settings.


#include "PluginActor.h"

// Sets default values
APluginActor::APluginActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;   

    // Initialize the sphere mesh
    InitializeSphereMesh();

    InitializeTextComponent();

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

void APluginActor::InitializeSphereMesh()
{
    // Create the sphere mesh component
    SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
    RootComponent = SphereMesh;

    // Load the sphere mesh from the Engine Content directory
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));

    if (SphereMeshAsset.Succeeded())
    {
        SphereMesh->SetStaticMesh(SphereMeshAsset.Object);
    }

    // Load a default material
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Game/StarterContent/Materials/M_Metal_Rust"));

    if (MaterialAsset.Succeeded())
    {
        SphereMesh->SetMaterial(0, MaterialAsset.Object);
    }

    // Enable physics and gravity
    SphereMesh->SetSimulatePhysics(true);
    SphereMesh->SetEnableGravity(true);
    SphereMesh->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
}

void APluginActor::InitializeTextComponent()
{
    // Create the text component
    TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
    TextComponent->SetupAttachment(RootComponent);
    TextComponent->SetText(FText::FromString("Hello from PluginActor.cpp!"));
    TextComponent->SetHorizontalAlignment(EHTA_Center);
    TextComponent->SetWorldSize(50.0f);
    TextComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f)); // Adjust position to be above the sphere
}

void APluginActor::SetActorText(const FString& text)
{
    TextComponent->SetText(FText::FromString(text));
}

