#include "DataAsset/StartUpData/DataAsset_BaseStartUpData.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/Abilitys/BaseGameplayAbility.h"

void UDataAsset_BaseStartUpData::GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InPlayerASCToGive, int32 ApplyLevel)
{
	// ASC 검사 매크로를 사용, 변수가 유효한지 체크
	check(InPlayerASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InPlayerASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InPlayerASCToGive, ApplyLevel);
}

void UDataAsset_BaseStartUpData::GrantAbilities(const TArray<TSubclassOf<UBaseGameplayAbility>>& InAbilitiesToGive, UBaseAbilitySystemComponent* InPlayerASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UBaseGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		// GIF 기능
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InPlayerASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InPlayerASCToGive->GiveAbility(AbilitySpec);
	}
}
