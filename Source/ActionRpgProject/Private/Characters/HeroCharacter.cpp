#include "Characters/HeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "DebugHelper.h"

AHeroCharacter::AHeroCharacter() // 전체적으로 캐릭터의 외형(캡슐), 카메라, 움직임
{
	// 캐릭터 충돌 범위 캡슐 크기 설정
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f); // 충돌 범위

	// 컨트롤러의 회전이 캐릭터에 직접 영향을 주지 않도록 설정 (카메라 독립 움직임)
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 카메라 암 설정
	// "CameraBoom"스프링암 컨포넌트 생성
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// 스프링 암을 캐릭터 루트에 부착 (루트 = 중심)
	CameraBoom->SetupAttachment(GetRootComponent());
	// 카메라와 캐릭터 사이의 기본 거리를 200으로 설정
	CameraBoom->TargetArmLength = 200.f;	
	// 카메라 위치를 캐릭터 중심에서 약간 위로, 뒤로 조정 (3인칭 시점)
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	// 컨트롤러의 회전에 따라 스프링 암이 회전하도록 설정
	CameraBoom->bUsePawnControlRotation = true;					

	// 팔로우 카메라 설정
	// "FollowCamera"스프링암 컨포넌트 생성
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// 카메라 스프링 암의 끝 부분(SocketName)에 부착
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// 카메라 자체는 컨트롤 회전을 사용하지 않도록 함 (부모인 스프링암이 이미 회전 중)
	FollowCamera->bUsePawnControlRotation = false;

	// 캐릭터 움직임 설정
	// 캐릭터가 이동하는 방향을 바라보도록 자동으로 회전 시킴
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// 캐릭터가 회전하는 속도를 초당 500으로 설정 (Y축 기준)
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	// 최대 걷는 속도를 400으로 설정
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	// 걷다가 멈출 때 감속하는 정도를 설정 (값일 클 수록 빠르게 멈춤)
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

}

void AHeroCharacter::BeginPlay() // 게임 시작 호출
{
	Super::BeginPlay(); // 클래스 가져와 재정의
	Debug::Print(TEXT("Working")); // Working 텍스트로 디버그 실행
}
