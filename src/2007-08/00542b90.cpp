// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_7075b163f138f154.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "RenderLib/Chunk.h"
#include "RenderLib/Profiler.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_AnchoredParts("ShowAnchors", "Display", &RBX::DebugSettings::getShowAnchoredParts, &RBX::DebugSettings::setShowAnchoredParts, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_HighlightSleepParts("HighlightSleepParts", "Display", &RBX::DebugSettings::getHighlightSleepParts, &RBX::DebugSettings::setHighlightSleepParts, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_HighlightAwakeParts("HighlightAwakeParts", "Display", &RBX::DebugSettings::getHighlightAwakeParts, &RBX::DebugSettings::setHighlightAwakeParts, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_PartCoordinateFrames("ShowPartCoords", "Display", &RBX::DebugSettings::getShowPartCoordinateFrames, &RBX::DebugSettings::setShowPartCoordinateFrames, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_UnalignedParts("ShowUnalignedParts", "Display", &RBX::DebugSettings::getShowUnalignedParts, &RBX::DebugSettings::setShowUnalignedParts, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_ShowAggregation("ShowAggregation", "Display", &RBX::DebugSettings::getShowAggregation, &RBX::DebugSettings::setShowAggregation, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_ModelCoordinateFrames("ShowModelCoords", "Display", &RBX::DebugSettings::getShowModelCoordinateFrames, &RBX::DebugSettings::setShowModelCoordinateFrames, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_WorldCoordinateFrames("ShowWorldCoords", "Display", &RBX::DebugSettings::getShowWorldCoordinateFrames, &RBX::DebugSettings::setShowWorldCoordinateFrames, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_SpanningTree("ShowTree", "Display", &RBX::DebugSettings::getShowSpanningTree, &RBX::DebugSettings::setShowSpanningTree, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_DisableSleep("DisableSleep", "Display", &RBX::DebugSettings::getDisableSleep, &RBX::DebugSettings::setDisableSleep, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_DisableEnvironmentalThrottle("DisableEnvironmentalThrottle", "Display", &RBX::DebugSettings::getDisableEnvironmentalThrottle, &RBX::DebugSettings::setDisableEnvironmentalThrottle, RBX::Reflection::PropertyDescriptor::STANDARD);

static RBX::Reflection::PropDescriptor<RBX::DebugSettings, bool> prop_ValidatingDebug("ValidatingDebug", "Errors", &RBX::DebugSettings::getValidatingDebug, &RBX::DebugSettings::setValidatingDebug, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, RBX::Debugable::AssertAction> prop_assertAction("AssertAction", "Errors", &RBX::DebugSettings::getAssertAction, &RBX::DebugSettings::setAssertAction, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, RBX::DebugSettings::ErrorReporting> prop_errorReporting("errorReporting", "Errors", &RBX::DebugSettings::getErrorReporting, &RBX::DebugSettings::setErrorReporting, RBX::Reflection::PropertyDescriptor::STANDARD);

static RBX::Reflection::PropDescriptor<RBX::DebugSettings, float> prop_shaderModel("ShaderModel", "Profile", &RBX::DebugSettings::shaderModel, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, int> prop_videoMemory("VideoMemory", "Profile", &RBX::DebugSettings::videoMemory, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, int> prop_cpuSpeed("CpuSpeed", "Profile", &RBX::DebugSettings::cpuSpeed, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, int> prop_osPlatformId("OsPlatformId", "Profile", &RBX::DebugSettings::osPlatformId, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_osVer("OsVer", "Profile", &RBX::DebugSettings::osVer, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_glVendor("GlVendor", "Profile", &RBX::DebugSettings::glVendor, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_gfxcard("GfxCard", "Profile", &RBX::DebugSettings::gfxcard, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_cpu("CPU", "Profile", &RBX::DebugSettings::cpu, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, int> prop_ram("RAM", "Profile", &RBX::DebugSettings::ram, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_resolution("Resolution", "Profile", &RBX::DebugSettings::resolution, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);

RBX::Reflection::BoundProp<bool, 1> prop_SoundWarnings("SoundWarnings", "Errors", &RBX::DebugSettings::soundWarnings, RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX
{
	DebugSettings::DebugSettings()
		: stackTracingEnabled(true),
		  ioEnabled(false),
		  soundWarnings(false),
		  errorReporting(Prompt)
	{
		setName("Diagnostics");
	}

	bool DebugSettings::getShowAnchoredParts() const
	{
		return PartInstance::showAnchoredParts;
	}

	bool DebugSettings::getShowAggregation() const
	{
		return Render::AggregateChunk::randomColors;
	}

	bool DebugSettings::getShowUnalignedParts() const
	{
		return PartInstance::showUnalignedParts;
	}

	bool DebugSettings::getHighlightSleepParts() const
	{
		return PartInstance::highlightSleepParts;
	}

	bool DebugSettings::getHighlightAwakeParts() const
	{
		return PartInstance::highlightAwakeParts;
	}

	bool DebugSettings::getShowPartCoordinateFrames() const
	{
		return PartInstance::showPartCoord;
	}

	bool DebugSettings::getShowModelCoordinateFrames() const
	{
		return ModelInstance::showModelCoord;
	}

	bool DebugSettings::getShowWorldCoordinateFrames() const
	{
		return Workspace::showWorldCoord;
	}

	bool DebugSettings::getDisableSleep() const
	{
		return Primitive::disableSleep;
	}

	bool DebugSettings::getDisableEnvironmentalThrottle() const
	{
		return World::disableEnvironmentalThrottle;
	}

	bool DebugSettings::getShowSpanningTree() const
	{
		return PartInstance::showSpanningTree;
	}

	void DebugSettings::setShowAnchoredParts(bool value)
	{
		if (value != PartInstance::showAnchoredParts)
		{
			PartInstance::showAnchoredParts = value;
			raisePropertyChanged(prop_AnchoredParts);
		}
	}

	void DebugSettings::setShowAggregation(bool value)
	{
		if (value != Render::AggregateChunk::randomColors)
		{
			Render::AggregateChunk::randomColors = value;
			raisePropertyChanged(prop_PartCoordinateFrames);
		}
	}

	void DebugSettings::setShowUnalignedParts(bool value)
	{
		if (value != PartInstance::showUnalignedParts)
		{
			PartInstance::showUnalignedParts = value;
			raisePropertyChanged(prop_PartCoordinateFrames);
		}
	}

	void DebugSettings::setHighlightSleepParts(bool value)
	{
		if (value != PartInstance::highlightSleepParts)
		{
			PartInstance::highlightSleepParts = value;
			raisePropertyChanged(prop_PartCoordinateFrames);
		}
	}

	void DebugSettings::setHighlightAwakeParts(bool value)
	{
		if (value != PartInstance::highlightAwakeParts)
		{
			PartInstance::highlightAwakeParts = value;
			raisePropertyChanged(prop_PartCoordinateFrames);
		}
	}

	void DebugSettings::setShowPartCoordinateFrames(bool value)
	{
		if (value != PartInstance::showPartCoord)
		{
			PartInstance::showPartCoord = value;
			raisePropertyChanged(prop_PartCoordinateFrames);
		}
	}

	void DebugSettings::setShowModelCoordinateFrames(bool value)
	{
		if (value != ModelInstance::showModelCoord)
		{
			ModelInstance::showModelCoord = value;
			raisePropertyChanged(prop_ModelCoordinateFrames);
		}
	}

	void DebugSettings::setShowWorldCoordinateFrames(bool value)
	{
		if (value != Workspace::showWorldCoord)
		{
			Workspace::showWorldCoord = value;
			raisePropertyChanged(prop_WorldCoordinateFrames);
		}
	}

	void DebugSettings::setDisableSleep(bool value)
	{
		if (value != Primitive::disableSleep)
		{
			Primitive::disableSleep = value;
			raisePropertyChanged(prop_DisableSleep);
		}
	}

	void DebugSettings::setDisableEnvironmentalThrottle(bool value)
	{
		if (value != World::disableEnvironmentalThrottle)
		{
			World::disableEnvironmentalThrottle = value;
			raisePropertyChanged(prop_DisableEnvironmentalThrottle);
		}
	}

	void DebugSettings::setShowSpanningTree(bool value)
	{
		if (value != PartInstance::showSpanningTree)
		{
			PartInstance::showSpanningTree = value;
			raisePropertyChanged(prop_SpanningTree);
		}
	}

	void DebugSettings::setValidatingDebug(bool value)
	{
		if (value != Debugable::validatingDebug)
		{
			Debugable::validatingDebug = value;
			raisePropertyChanged(prop_ValidatingDebug);
		}
	}

	void DebugSettings::setAssertAction(Debugable::AssertAction value)
	{
		if (value != Debugable::assertAction)
		{
			Debugable::assertAction = value;
			raisePropertyChanged(prop_assertAction);
		}
	}

	void DebugSettings::setErrorReporting(ErrorReporting value)
	{
		if (value != errorReporting)
		{
			errorReporting = value;
			raisePropertyChanged(prop_errorReporting);
		}
	}

	float DebugSettings::shaderModel() const
	{
		return Render::SpecData().shaderModel;
	}

	int DebugSettings::videoMemory() const
	{
		return Render::SpecData().videoMemory;
	}

	int DebugSettings::cpuSpeed() const
	{
		return Render::SpecData().CPUSpeed;
	}

	std::string DebugSettings::glVendor() const
	{
		return Render::SpecData().glVendor;
	}

	std::string DebugSettings::cpu() const
	{
		return Render::SpecData().cpu;
	}

	int DebugSettings::ram() const
	{
		return Render::SpecData().ram;
	}

	std::string DebugSettings::resolution() const
	{
		return Render::SpecData().resolution;
	}

	std::string DebugSettings::osVer() const
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD)); // dwOSVersionInfoSize is the first element
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return G3D::format("%d.%d.%d.%d", osvi.dwOSVersionInfoSize, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
	}

	int DebugSettings::osPlatformId() const
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return osvi.dwPlatformId;
	}
}
