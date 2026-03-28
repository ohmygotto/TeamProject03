#include "MyActor.h"
#include "Engine/Engine.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.f, 50.f, 0.f));

	PrintCurrentLocation();

	for (int32 i = 0; i < 10; ++i)
	{
		float RandomDistance = FMath::FRandRange(50.f, 200.f);
		float RandomAngle = FMath::FRandRange(-180.f, 180.f);

		Move(RandomDistance);
		Turn(RandomAngle);
	}
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::Move(float Distance)
{
	FVector CurrentLocation = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();

	FVector NewLocation = CurrentLocation + ForwardVector * Distance;
	SetActorLocation(NewLocation);

	PrintCurrentLocation();
}

void AMyActor::Turn(float Angle)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Yaw += Angle;
	SetActorRotation(CurrentRotation);
}

void AMyActor::PrintCurrentLocation()
{
	FVector CurrentLocation = GetActorLocation();

	FString Message = FString::Printf(
		TEXT("Location : X = %.2f, Y = %.2f, Z = %.2f"),
		CurrentLocation.X,
		CurrentLocation.Y,
		CurrentLocation.Z
	);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			3.0f,
			FColor::Green,
			Message
		);
	}
}