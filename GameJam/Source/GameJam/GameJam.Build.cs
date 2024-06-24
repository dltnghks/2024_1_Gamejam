// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameJam : ModuleRules
{
	public GameJam(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "Water" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "NavigationSystem", "AIModule", "Niagara" });
	}
}
