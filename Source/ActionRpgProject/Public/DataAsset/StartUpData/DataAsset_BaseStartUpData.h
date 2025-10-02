#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_BaseStartUpData.generated.h"

class UBaseGameplayAbility;
class UBaseAbilitySystemComponent;
UCLASS()
class ACTIONRPGPROJECT_API UDataAsset_BaseStartUpData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	// 기본 값만 편집 가능 카테고리, 데이터 = StartUpData
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	// Player 어빌리티 UBaseGameplayAbility에서 상속
	TArray < TSubclassOf < UBaseGameplayAbility > > ActivateOnGivenAbilities;

	// 특정 조건에서 발동되는 히트 리액트 or 사망 관련 어빌리티 배열
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray < TSubclassOf < UBaseGameplayAbility > > ReactiveAbilities;

	void GrantAbilities(const TArray < TSubclassOf < UBaseGameplayAbility > >& InAbilitiesToGive, UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
