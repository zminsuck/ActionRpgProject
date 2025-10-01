#include "AbilitySystem/Abilitys/BaseGameplayAbility.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"

// 어빌리티 시스템 컴포넌트에 어빌리티가 부여 된 직후 호출
void UBaseGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbuilityAcftivationPolicy == EAbuilityAcftivationPolicy::OnGiven)
	{
		if (ActorInfo && Spec.IsActive()) // 게임 플레이 기능이 활성화 되어 있지 않으면 활성화
		{
			// 액터에서 어빌리티 시스템 컴포넌트 액세스
			// 함수 기능 활성화 -> Fps플레이 백 핸들
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UBaseGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbuilityAcftivationPolicy == EAbuilityAcftivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}
