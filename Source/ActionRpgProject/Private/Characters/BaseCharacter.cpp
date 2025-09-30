#include "Characters/BaseCharacter.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

ABaseCharacter::ABaseCharacter()
{
	// 모든 캐릭터 클래스에 대해 변경하고 싶은 것이 없음
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 차후 사용할 VFX는 바닥에 데칼을 투사 = 캐릭터 메시가 아닌 바닥에만 투사하라는 의미
	GetMesh()->bReceivesDecals = false;

	BaseAbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("BaseAbilitySystemComponent"));
		
	BaseAttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("BaseAttributeSet"));
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return GetBaseAbilitySystemComponent();
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 어빌리티 시스템 구성요소 유효한지 체크
	if (BaseAbilitySystemComponent)
	{
		// 초기화 어빌리티 액터 정보
		BaseAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}


