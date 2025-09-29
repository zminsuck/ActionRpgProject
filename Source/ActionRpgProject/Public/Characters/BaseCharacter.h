#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ACTIONRPGPROJECT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:				  // 접근 지정자 공개
	ABaseCharacter(); // 클래스 선언
};
