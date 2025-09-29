#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "HeroCharacter.generated.h"

class USpringArmComponent; // 스프링암 구성요소
class UCameraComponent; // 카메라 컨포넌트


UCLASS()
class ACTIONRPGPROJECT_API AHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AHeroCharacter();
protected: // 클래스 선언
	virtual void BeginPlay() override; // BeginPlay 클래스 오버라이드

private: // 접근 지정자 프라이빗

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
#pragma endregion
};
