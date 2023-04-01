// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CS380_FinalCPP/CS380_FinalCPPGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCS380_FinalCPPGameModeBase() {}
// Cross Module References
	CS380_FINALCPP_API UClass* Z_Construct_UClass_ACS380_FinalCPPGameModeBase_NoRegister();
	CS380_FINALCPP_API UClass* Z_Construct_UClass_ACS380_FinalCPPGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CS380_FinalCPP();
// End Cross Module References
	void ACS380_FinalCPPGameModeBase::StaticRegisterNativesACS380_FinalCPPGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACS380_FinalCPPGameModeBase);
	UClass* Z_Construct_UClass_ACS380_FinalCPPGameModeBase_NoRegister()
	{
		return ACS380_FinalCPPGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CS380_FinalCPP,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CS380_FinalCPPGameModeBase.h" },
		{ "ModuleRelativePath", "CS380_FinalCPPGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACS380_FinalCPPGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::ClassParams = {
		&ACS380_FinalCPPGameModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACS380_FinalCPPGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ACS380_FinalCPPGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACS380_FinalCPPGameModeBase.OuterSingleton, Z_Construct_UClass_ACS380_FinalCPPGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACS380_FinalCPPGameModeBase.OuterSingleton;
	}
	template<> CS380_FINALCPP_API UClass* StaticClass<ACS380_FinalCPPGameModeBase>()
	{
		return ACS380_FinalCPPGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACS380_FinalCPPGameModeBase);
	struct Z_CompiledInDeferFile_FID_CS380_FinalCPP_Source_CS380_FinalCPP_CS380_FinalCPPGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CS380_FinalCPP_Source_CS380_FinalCPP_CS380_FinalCPPGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACS380_FinalCPPGameModeBase, ACS380_FinalCPPGameModeBase::StaticClass, TEXT("ACS380_FinalCPPGameModeBase"), &Z_Registration_Info_UClass_ACS380_FinalCPPGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACS380_FinalCPPGameModeBase), 1267558298U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CS380_FinalCPP_Source_CS380_FinalCPP_CS380_FinalCPPGameModeBase_h_2736860048(TEXT("/Script/CS380_FinalCPP"),
		Z_CompiledInDeferFile_FID_CS380_FinalCPP_Source_CS380_FinalCPP_CS380_FinalCPPGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CS380_FinalCPP_Source_CS380_FinalCPP_CS380_FinalCPPGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
