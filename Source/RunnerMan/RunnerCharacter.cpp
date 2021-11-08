// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	this->SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side Camera"));
	this->SideViewCamera->bUsePawnControlRotation = false; // Not rotate the camera

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.f, 0.0f);

	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.8f;

	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	_TempPos = GetActorLocation();

	_zPosition = _TempPos.Z + 200.0f;
}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	_canMove = true;
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	_TempPos = GetActorLocation();
	_TempPos.X -= 850.0f;
	_TempPos.Z = _zPosition;

	SideViewCamera->SetWorldLocation(_TempPos);
}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const FName jumpAction = "Jump";

	PlayerInputComponent->BindAction(jumpAction, IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction(jumpAction, IE_Released, this,  &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ARunnerCharacter::MoveRight);
}

void ARunnerCharacter::MoveRight(float value)
{
	if (_canMove)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value);
	}
}

void ARunnerCharacter::RestartLevel()
{

}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 bodyIndex, bool isBFromSweep, const FHitResult& SweepResult)
{

}

