// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPS : ModuleRules
{
    public TPS(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay",
            "EnhancedInput",
            "UMG",
            "GameplayTags",
            "NavigationSystem",
            "AIModule",
            "GameplayTasks",
            "ChaosVehicles"
        });
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Slate",
            "SlateCore",
        });
    }
}
