// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ROSIntegration/Classes/RI/Topic.h"
#include "ROSIntegration/Classes/ROSIntegrationGameInstance.h"

#include "TestROSIntegrationActor.generated.h"

UCLASS()
class TESTROSINTEGRATION_API ATestROSIntegrationActor : public AActor
{
	GENERATED_BODY()

private:
	UTopic *ExampleTopic;
	
public:	
	// Sets default values for this actor's properties
	ATestROSIntegrationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
