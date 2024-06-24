// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamCharacter.h"
#include "GameJamProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PhysicsVolume.h"


//////////////////////////////////////////////////////////////////////////
// AGameJamCharacter

AGameJamCharacter::AGameJamCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void AGameJamCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

void AGameJamCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(bInWater)
	{
		float CalcZ = WaterZ - GetActorLocation().Z;
		float CapsuleHalfHeight = GetCapsuleComponent()->GetCollisionShape().GetCapsuleHalfHeight();
		if(CalcZ > CapsuleHalfHeight)
		{
			UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
			if(!bIsSwimming) {
				UE_LOG(LogTemp, Log, TEXT("SetSwimming"));
				bIsSwimming = true;
				
				CharacterMovementComp->GetPhysicsVolume()->bWaterVolume = true;
				CharacterMovementComp->SetMovementMode(MOVE_Swimming);
				
			}
		} else if(CalcZ < CapsuleHalfHeight)
		{
			UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
			if(bIsSwimming) {
				bIsSwimming = false;
				UE_LOG(LogTemp, Log, TEXT("SetWalking"));
				CharacterMovementComp->GetPhysicsVolume()->bWaterVolume = true;
				CharacterMovementComp->SetMovementMode(MOVE_Walking);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void AGameJamCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGameJamCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGameJamCharacter::Look);
	}
}

void AGameJamCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AGameJamCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGameJamCharacter::Jump()
{
	Super::Jump();

	if(bInWater)
	{
		AddMovementInput(GetActorUpVector(), 0.5f);
	}
}

void AGameJamCharacter::StopJumping()
{
	Super::StopJumping();
}

void AGameJamCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool AGameJamCharacter::GetHasRifle()
{
	return bHasRifle;
}

void AGameJamCharacter::EnterWater()
{
	bInWater = true;
	
	WaterZ = GetActorLocation().Z;
	UE_LOG(LogTemp, Log, TEXT("EnterWater"));
}


void AGameJamCharacter::ExitWater()
{
	bInWater = false;
	UE_LOG(LogTemp, Log, TEXT("ExitWater"));
}