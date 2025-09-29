#include "DataAsset/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeINputActionByTag(const FGameplayTag& InInputTag)
{
	for (const FPlayerInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}

	return nullptr;
}
