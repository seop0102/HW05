// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	position = FVector2D(0, 0); //Ω√¿€¡°
	eventnum = 0;
	sum = 0.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float x = second.X - first.X;
	float y = second.Y - first.Y;
	return FMath::Sqrt((x * x) + (y * y));
}

void AMyActor::move()
{
	for (int32 i = 0; i < 10; i++) {
		int32 x = step();
		int32 y = step();
		FVector2D a = position;
		position.X += x;
		position.Y += y;

		float dis = distance(a, position);
		sum += dis;
		int32 b = createEvent();
		if (b == 1) {
			eventnum++;
			UE_LOG(LogTemp, Warning, TEXT("OOOOO Event OOOOO"));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("XXXXX Event XXXXX"));
		}

		UE_LOG(LogTemp, Warning, TEXT("(%.0f, %.0f)"), position.X, position.Y);
	}
	UE_LOG(LogTemp, Warning, TEXT("sum: %.2f"), sum);
	UE_LOG(LogTemp, Warning, TEXT("eventnum: %d"), eventnum);

}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

int32 AMyActor::createEvent()
{
	return FMath::RandRange(0, 1);
}



