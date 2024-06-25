// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamCharacter.h"
#include "GameJamProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameJamGameMode.h"
#include "InGameUI.h"
#include "ShockWave.h"
#include "ShockWaveNiagaraActor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PhysicsVolume.h"
#include "Kismet/GameplayStatics.h"
#include "Managers/ResourceManager.h"
#include "Object/ObjSoapBubble.h"


//////////////////////////////////////////////////////////////////////////
// AGameJamCharacter

class AGameJamGameMode;

AGameJamCharacter::AGameJamCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	ShockWaveRot = FRotator(0, 0, 90);
}

void AGameJamCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	InGameUI = CreateWidget<UInGameUI>(GetWorld(), BP_InGameUI);
	InGameUI->AddToViewport();
}

void AGameJamCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CurShockWaveCoolDown > 0)
	{
		CurShockWaveCoolDown -= DeltaSeconds;
		InGameUI->SetCoolDown(FString::FromInt(CurShockWaveCoolDown));
	}
	else
	{
		InGameUI->SetCoolDown(FString("LMB!"));
	}

	if (bInWater)
	{
		float CalcZ = WaterZ - GetActorLocation().Z;
		float CapsuleHalfHeight = GetCapsuleComponent()->GetCollisionShape().GetCapsuleHalfHeight();
		if (CalcZ > CapsuleHalfHeight)
		{
			UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
			if (!bIsSwimming)
			{
				UE_LOG(LogTemp, Log, TEXT("SetSwimming"));
				bIsSwimming = true;

				CharacterMovementComp->GetPhysicsVolume()->bWaterVolume = true;
				CharacterMovementComp->SetMovementMode(MOVE_Swimming);
			}
		}
		else if (CalcZ <= CapsuleHalfHeight)
		{
			UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
			if (bIsSwimming)
			{
				bIsSwimming = false;
				UE_LOG(LogTemp, Log, TEXT("SetWalking"));
				CharacterMovementComp->GetPhysicsVolume()->bWaterVolume = false;
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

		//Skill
		EnhancedInputComponent->BindAction(SkillAction, ETriggerEvent::Triggered, this, &AGameJamCharacter::Skill);

		//SpawnBubble
		EnhancedInputComponent->BindAction(SoapBubbleAction, ETriggerEvent::Triggered, this,
		                                   &AGameJamCharacter::SpawnSoapBubble);
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

	if (bInWater)
	{
		AddMovementInput(GetActorUpVector(), 0.5f);
	}
}

void AGameJamCharacter::StopJumping()
{
	Super::StopJumping();
}

void AGameJamCharacter::Skill()
{
	if (CurShockWaveCoolDown <= 0)
	{
		CurShockWaveCoolDown = ShockWaveCoolDown;
		AShockWave* ShockWave = GetWorld()->SpawnActor<AShockWave>(BP_ShockWave, GetActorLocation(), ShockWaveRot);
	}
}

void AGameJamCharacter::SpawnSoapBubble()
{
	AGameJamGameMode* gameMode = Cast<AGameJamGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	AObjSoapBubble* newSoapBubble = gameMode->ResourceManager->Instantiate<AObjSoapBubble>(BP_SoapBubble);
	newSoapBubble->Init(GetActorLocation(), gameMode->Destination);
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
	bIsSwimming = false;
	UCharacterMovementComponent* CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->GetPhysicsVolume()->bWaterVolume = false;
	CharacterMovementComp->SetMovementMode(MOVE_Walking);
	UE_LOG(LogTemp, Log, TEXT("ExitWater"));
}
