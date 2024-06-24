// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameJam/GameJamGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameJamGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
GAMEJAM_API UClass* Z_Construct_UClass_AGameJamGameMode();
GAMEJAM_API UClass* Z_Construct_UClass_AGameJamGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_GameJam();
// End Cross Module References

// Begin Class AGameJamGameMode
void AGameJamGameMode::StaticRegisterNativesAGameJamGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameJamGameMode);
UClass* Z_Construct_UClass_AGameJamGameMode_NoRegister()
{
	return AGameJamGameMode::StaticClass();
}
struct Z_Construct_UClass_AGameJamGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameJamGameMode.h" },
		{ "ModuleRelativePath", "GameJamGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameJamGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGameJamGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GameJam,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameJamGameMode_Statics::ClassParams = {
	&AGameJamGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameJamGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameJamGameMode()
{
	if (!Z_Registration_Info_UClass_AGameJamGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameJamGameMode.OuterSingleton, Z_Construct_UClass_AGameJamGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameJamGameMode.OuterSingleton;
}
template<> GAMEJAM_API UClass* StaticClass<AGameJamGameMode>()
{
	return AGameJamGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameJamGameMode);
AGameJamGameMode::~AGameJamGameMode() {}
// End Class AGameJamGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameJamGameMode, AGameJamGameMode::StaticClass, TEXT("AGameJamGameMode"), &Z_Registration_Info_UClass_AGameJamGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameJamGameMode), 4294601578U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamGameMode_h_127231957(TEXT("/Script/GameJam"),
	Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
