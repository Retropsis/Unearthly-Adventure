// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unearthly : ModuleRules
{
	public Unearthly(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GeometryCollectionEngine", "UMG" });
	}
}
