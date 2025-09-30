#include "AnimInstances/AllCharacterAnim.h"
#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AnimInstances/Hero/HeroCharacterAnim.h"

void UAllCharacterAnim::NativeInitializeAnimation()
{
	// 가져오기 함수
	OwningCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter) // 현재 조건 캐릭터가 유효 -> 컴포넌트 엑세스
	{
		OwnigMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UAllCharacterAnim::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwnigMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwnigMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}