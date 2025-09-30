using UnrealBuildTool;

public class ActionRpgProject : ModuleRules
{
	public ActionRpgProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
            "InputCore",
            "GameplayTags",
            "EnhancedInput",
			"GameplayTasks" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
