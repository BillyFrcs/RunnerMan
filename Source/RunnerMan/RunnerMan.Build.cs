// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RunnerMan : ModuleRules
{
	public RunnerMan(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
