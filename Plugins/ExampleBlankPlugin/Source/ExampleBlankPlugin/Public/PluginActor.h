// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "PluginActor.generated.h"

UCLASS()
class EXAMPLEBLANKPLUGIN_API APluginActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APluginActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Sphere mesh component
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SphereMesh;

	// Text render component
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UTextRenderComponent* TextComponent;

	// Function to initialize the sphere mesh
	void InitializeSphereMesh();

	void InitializeTextComponent();

	UFUNCTION(BlueprintCallable, Category = "PluginExample")
	void SetActorText(const FString& text);

};
