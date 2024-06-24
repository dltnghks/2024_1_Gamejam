// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameJam/GameJamPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameJamPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
GAMEJAM_API UClass* Z_Construct_UClass_AGameJamPlayerController();
GAMEJAM_API UClass* Z_Construct_UClass_AGameJamPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_GameJam();
// End Cross Module References

// Begin Class AGameJamPlayerController
void AGameJamPlayerController::StaticRegisterNativesAGameJamPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameJamPlayerController);
UClass* Z_Construct_UClass_AGameJamPlayerController_NoRegister()
{
	return AGameJamPlayerController::StaticClass();
}
struct Z_Construct_UClass_AGameJamPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "GameJamPlayerController.h" },
		{ "ModuleRelativePath", "GameJamPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Context to be used for player input */" },
#endif
		{ "ModuleRelativePath", "GameJamPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Context to be used for player input" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameJamPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameJamPlayerController_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameJamPlayerController, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameJamPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameJamPlayerController_Statics::NewProp_InputMappingContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGameJamPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_GameJam,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameJamPlayerController_Statics::ClassParams = {
	&AGameJamPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGameJamPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameJamPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameJamPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameJamPlayerController()
{
	if (!Z_Registration_Info_UClass_AGameJamPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameJamPlayerController.OuterSingleton, Z_Construct_UClass_AGameJamPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameJamPlayerController.OuterSingleton;
}
template<> GAMEJAM_API UClass* StaticClass<AGameJamPlayerController>()
{
	return AGameJamPlayerController::StaticClass();
}
AGameJamPlayerController::AGameJamPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameJamPlayerController);
AGameJamPlayerController::~AGameJamPlayerController() {}
// End Class AGameJamPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameJamPlayerController, AGameJamPlayerController::StaticClass, TEXT("AGameJamPlayerController"), &Z_Registration_Info_UClass_AGameJamPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameJamPlayerController), 1520707582U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamPlayerController_h_4064992616(TEXT("/Script/GameJam"),
	Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
