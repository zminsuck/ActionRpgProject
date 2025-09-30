#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "AllCharacterAnim.generated.h"

class ABaseCharacter;
class UCharacterMovementComponent;

UCLASS()
class ACTIONRPGPROJECT_API UAllCharacterAnim : public UBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;

	// 성능 번목현상 최적화
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY()
	ABaseCharacter* OwningCharacter;

	UPROPERTY() // 넣지 않으면 포인터 메모리가 영원히 남음
	UCharacterMovementComponent* OwnigMovementComponent;

	// 항목 기본 표시, 청사진 읽기 전용, 하위 카테고리 제작 Ndum 데이터 입력
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
