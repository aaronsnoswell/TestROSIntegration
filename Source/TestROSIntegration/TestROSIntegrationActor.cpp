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

	UROSIntegrationGameInstance* GI = Cast<UROSIntegrationGameInstance>(GetGameInstance());

	ExamplePublishTopic = NewObject<UTopic>(UTopic::StaticClass());
	ExamplePublishTopic->Init(GI->_Ric, TEXT("/chatter_foozle"), TEXT("std_msgs/String"));
	PublishStringMessage = TSharedPtr<ROSMessages::std_msgs::String>(new ROSMessages::std_msgs::String("This is an example"));

	ExampleSubscribeTopic = NewObject<UTopic>(UTopic::StaticClass());
	ExampleSubscribeTopic->Init(GI->_Ric, TEXT("/chatter"), TEXT("std_msgs/String"));
	std::function<void(TSharedPtr<FROSBaseMsg>)> SubscribeCallback = [](TSharedPtr<FROSBaseMsg> msg) -> void 
	{
		UE_LOG(LogTemp, Log, TEXT("GOT INCOMING /CHATTER"));
		return;
	};

	ExampleSubscribeTopic->Subscribe(SubscribeCallback);
}

// Called every frame
void ATestROSIntegrationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//ExampleTopic->Publish(StringMessage);

}

