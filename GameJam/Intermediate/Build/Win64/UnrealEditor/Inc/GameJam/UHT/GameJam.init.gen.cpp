// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameJam_init() {}
	GAMEJAM_API UFunction* Z_Construct_UDelegateFunction_GameJam_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GameJam;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GameJam()
	{
		if (!Z_Registration_Info_UPackage__Script_GameJam.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GameJam_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GameJam",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xA462655B,
				0x6BE5F72A,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GameJam.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GameJam.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GameJam(Z_Construct_UPackage__Script_GameJam, TEXT("/Script/GameJam"), Z_Registration_Info_UPackage__Script_GameJam, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xA462655B, 0x6BE5F72A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
