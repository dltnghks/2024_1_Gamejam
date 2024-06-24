// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameJamProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef GAMEJAM_GameJamProjectile_generated_h
#error "GameJamProjectile.generated.h already included, missing '#pragma once' in GameJamProjectile.h"
#endif
#define GAMEJAM_GameJamProjectile_generated_h

#define FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameJamProjectile(); \
	friend struct Z_Construct_UClass_AGameJamProjectile_Statics; \
public: \
	DECLARE_CLASS(AGameJamProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GameJam"), NO_API) \
	DECLARE_SERIALIZER(AGameJamProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGameJamProjectile(AGameJamProjectile&&); \
	AGameJamProjectile(const AGameJamProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameJamProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameJamProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameJamProjectile) \
	NO_API virtual ~AGameJamProjectile();


#define FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_12_PROLOG
#define FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEJAM_API UClass* StaticClass<class AGameJamProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_leejo_Desktop_2024_1_Gamejam_GameJam_Source_GameJam_GameJamProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
