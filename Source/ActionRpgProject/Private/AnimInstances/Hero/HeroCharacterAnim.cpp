#include "AnimInstances/Hero/HeroCharacterAnim.h"
#include "Characters/HeroCharacter.h"

void UHeroCharacterAnim::NativeInitializeAnimation()
{
	// 자체 버전 재정의
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AHeroCharacter>(OwningCharacter);
	}
}

void UHeroCharacterAnim::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;
		
		bShouldEnterRelaxState = (IdleElpasedTime > EnterRelaxStateThreshold);
	}
}

