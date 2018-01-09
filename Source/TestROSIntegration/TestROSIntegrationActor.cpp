// Fill out your copyright notice in the Description page of Project Settings.

#include "TestROSIntegrationActor.h"



// Sets default values
ATestROSIntegrationActor::ATestROSIntegrationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestROSIntegrationActor::BeginPlay()
{
	Super::BeginPlay();

	ExampleTopic = NewObject<UTopic>(UTopic::StaticClass());
	UROSIntegrationGameInstance* rosinst = Cast<UROSIntegrationGameInstance>(GetGameInstance());
	ExampleTopic->Init(rosinst->_Ric, TEXT("/chatter_foozle"), TEXT("std_msgs/String"));
	
}

// Called every frame
void ATestROSIntegrationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TSharedPtr<ROSMessages::std_msgs::String> StringMessage(new ROSMessages::std_msgs::String("This is an example"));
	ExampleTopic->Publish(StringMessage);

}

