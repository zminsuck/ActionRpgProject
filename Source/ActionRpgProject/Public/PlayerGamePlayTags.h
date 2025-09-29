#pragma once

#include "NativeGameplayTags.h"

namespace PlayerGamePlayTags
{
	/** Input Tags **/
	// 이동 입력을 식별하는 데 사용
	ACTIONRPGPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	// 시점 조작 입력을 식별하는 데 사용
	ACTIONRPGPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
}

/** 간단 설명 요약 **/
/*
1. 게임에서 사용할 "이동입력", "시점 조작 입력"에 대한 전용 이름표를 만들 준비
2. 선언된 태그들은 .cpp 파일에서 매크로를 통해 실제 태그 값과 연결
3. 플레이어의 입력을 감지, 처리하는데 사용됨
*/
