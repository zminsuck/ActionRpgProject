#include "Characters/BaseCharacter.h"


ABaseCharacter::ABaseCharacter()
{
	// 모든 캐릭터 클래스에 대해 변경하고 싶은 것이 없음
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 차후 사용할 VFX는 바닥에 데칼을 투사 = 캐릭터 메시가 아닌 바닥에만 투사하라는 의미
	GetMesh()->bReceivesDecals = false;
}


