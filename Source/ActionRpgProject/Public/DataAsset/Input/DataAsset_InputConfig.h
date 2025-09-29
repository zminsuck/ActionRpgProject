#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h" // 게임 플레이 태그 헤더
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;
USTRUCT(BlueprintType)
struct FPlayerInputActionConfig
{
	GENERATED_BODY()

public:
	// 기본 값만 편집, 블루프린트 읽기 전용. InputTag로 시작하는 태그만 선택 가능
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;
};

UCLASS()
class ACTIONRPGPROJECT_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FPlayerInputActionConfig> NativeInputActions; // 네이티브 입력 액션

	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
