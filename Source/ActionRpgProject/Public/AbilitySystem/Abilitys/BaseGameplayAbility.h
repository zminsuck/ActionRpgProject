#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

UENUM(BlueprintType) // 열거형 블루프린트
enum class EAbuilityAcftivationPolicy : uint8
{
	OnTriggered, // 트리거 경우
	OnGiven // 주어진 경우
};

UCLASS()
class ACTIONRPGPROJECT_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:

	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	// 기본 값이 트리거 되지 않음
	EAbuilityAcftivationPolicy AbuilityAcftivationPolicy = EAbuilityAcftivationPolicy::OnTriggered;
};
