#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UBaseAbilitySystemComponent; // 어빌리티 컴포넌트 포워드 선언
class UBaseAttributeSet;		   // 어빌티리 속성 포워드 선언

UCLASS()
class ACTIONRPGPROJECT_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:				  // 접근 지정자 공개
	ABaseCharacter(); // 클래스 선언
	
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface

protected:

	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	// 카테고리 = 능력 시스템
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBaseAbilitySystemComponent* BaseAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UBaseAttributeSet* BaseAttributeSet;

public:
	// 강제 인라인 - 어빌리티 시스템
	FORCEINLINE UBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() const { return BaseAbilitySystemComponent; }

	// 강제 인라인 - 어빌리티 속성
	FORCEINLINE UBaseAttributeSet* GetUBaseAttributeSet() const { return BaseAttributeSet; }
};
