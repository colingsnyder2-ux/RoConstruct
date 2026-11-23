// =============================================================================
// DebugSettings.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/DebugSettings.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h" // showModelCoord for setShowModelCoordinateFrames (same include as DebugSettingsCoordinateGetters.cpp)
#include "reflection/enumconverter.h"
#include <G3D/format.h>
#include <stdexcept>

#include "AppUnit500/RenderSpecData.h"

namespace RBX
{
	const char sDebugSettings[] = "DebugSettings"; // 0082dfb8

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL; // 0096c318

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		setName(ClassName);
		if (sing)
			throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
		sing = this;
	}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		sing = NULL;
	}

	Reflection::EnumDesc<DebugSettings::ErrorReporting>::EnumDesc()         // 00564a60
		: EnumDescriptor("ErrorReporting", typeid(DebugSettings::ErrorReporting))
	{
		addPair(DebugSettings::DontReport, "DontReport");
		addPair(DebugSettings::Prompt, "Prompt");
		addPair(DebugSettings::Report, "Report");
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	Reflection::EnumDesc<World::EThrottle>::EnumDesc()                      // 00564be0
		: EnumDescriptor("EnviromentalPhysicsThrottle", typeid(World::EThrottle))
	{
		addPair(World::DefaultAuto, "DefaultAuto");
		addPair(World::Disabled, "Disabled");
		addPair(World::Random, "Random");
		addPair(World::Always, "Always");
	}
#endif

	Reflection::EnumDesc<Debugable::AssertAction>::EnumDesc()               // 00564d70
		: EnumDescriptor("AssertAction", typeid(Debugable::AssertAction))
	{
		addPair(Debugable::CrashOnAssert, "CrashOnAssert");
		addPair(Debugable::IgnoreAssert, "IgnoreAssert");
	}

	static Reflection::PropDescriptor<DebugSettings, float> prop_ShaderModel(
		"ShaderModel",
		"Profile",
		&DebugSettings::shaderModel,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_VideoMemory(
		"VideoMemory",
		"Profile",
		&DebugSettings::videoMemory,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_CpuSpeed(
		"CpuSpeed",
		"Profile",
		&DebugSettings::cpuSpeed,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_CpuCount(
		"CpuCount",
		"Profile",
		&DebugSettings::cpuCount,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_OsPlatformId(
		"OsPlatformId",
		"Profile",
		&DebugSettings::osPlatformId,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_OsVer(
		"OsVer",
		"Profile",
		&DebugSettings::osVer,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_SystemProductName(
		"SystemProductName",
		"Profile",
		&DebugSettings::systemProductName,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_GlVendor(
		"GlVendor",
		"Profile",
		&DebugSettings::glVendor,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_GfxCard(
		"GfxCard",
		"Profile",
		&DebugSettings::gfxcard,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_CPU(
		"CPU",
		"Profile",
		&DebugSettings::cpu,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, int> prop_RAM(
		"RAM",
		"Profile",
		&DebugSettings::ram,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, std::string> prop_Resolution(
		"Resolution",
		"Profile",
		&DebugSettings::resolution,
		NULL,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoundWarnings(
		"SoundWarnings",
		"Errors",
		&DebugSettings::soundWarnings,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_StackTracingEnabled(
		"stackTracingEnabled",
		"Scripts",
		&DebugSettings::stackTracingEnabled,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_IoEnabled(
		"ioEnabled",
		"Scripts",
		&DebugSettings::ioEnabled,
		Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowAnchors(
		"ShowAnchors",
		"Display",
		&DebugSettings::getShowAnchoredParts,
		&DebugSettings::setShowAnchoredParts,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowPartCoords(
		"ShowPartCoords",
		"Display",
		&DebugSettings::getShowPartCoordinateFrames,
		&DebugSettings::setShowPartCoordinateFrames,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowUnalignedParts(
		"ShowUnalignedParts",
		"Display",
		&DebugSettings::getShowUnalignedParts,
		&DebugSettings::setShowUnalignedParts,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowModelCoords(
		"ShowModelCoords",
		"Display",
		&DebugSettings::getShowModelCoordinateFrames,
		&DebugSettings::setShowModelCoordinateFrames,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ShowWorldCoords(
		"ShowWorldCoords",
		"Display",
		&DebugSettings::getShowWorldCoordinateFrames,
		&DebugSettings::setShowWorldCoordinateFrames,
		Reflection::PropertyDescriptor::STANDARD);
#ifdef NATIVE_DEBUGSETTINGS_PENDING
	static Reflection::EnumPropDescriptor<DebugSettings, World::EThrottle> prop_PhysicsEnviromentalThrottle(
		"PhysicsEnviromentalThrottle",
		"Throttle",
		&DebugSettings::getEnvironmentalThrottle,
		&DebugSettings::setEnvironmentalThrottle,
		Reflection::PropertyDescriptor::STANDARD);
#endif
	static Reflection::PropDescriptor<DebugSettings, bool> prop_30FpsThrottle(
		"30FpsThrottle",
		"Throttle",
		&DebugSettings::get30FpsThrottle,
		&DebugSettings::set30FpsThrottle,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_DistributedPhysics(
		"DistributedPhysics",
		"Throttle",
		&DebugSettings::getDistributedPhysics,
		&DebugSettings::setDistributedPhysics,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, double> prop_ProfilerWindow(
		"ProfilerWindow",
		"Profiling",
		&DebugSettings::getProfilerWindow,
		&DebugSettings::setProfilerWindow,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, double> prop_ProfilerBucketTimeSpan(
		"ProfilerBucketTimeSpan",
		"Profiling",
		&DebugSettings::getProfilerBucketTimeSpan,
		&DebugSettings::setProfilerBucketTimeSpan,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<DebugSettings, bool> prop_ValidatingDebug(
		"ValidatingDebug",
		"Errors",
		&DebugSettings::getValidatingDebug,
		&DebugSettings::setValidatingDebug,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<DebugSettings, Debugable::AssertAction> prop_AssertAction(
		"AssertAction",
		"Errors",
		&DebugSettings::getAssertAction,
		&DebugSettings::setAssertAction,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<DebugSettings, DebugSettings::ErrorReporting> prop_ErrorReporting(
		"errorReporting",
		"Errors",
		&DebugSettings::getErrorReporting,
		&DebugSettings::setErrorReporting,
		Reflection::PropertyDescriptor::STANDARD);

	DebugSettings::DebugSettings()
		: stackTracingEnabled(true),
		  ioEnabled(false),
		  soundWarnings(false),
		  errorReporting(Prompt)
	{
		setName("Diagnostics");
	}

	bool DebugSettings::getValidatingDebug() const
	{
		return Debugable::validatingDebug;
	}

	Debugable::AssertAction DebugSettings::getAssertAction() const
	{
		return Debugable::assertAction;
	}

	bool DebugSettings::getShowAnchoredParts() const
	{
		return PartInstance::showAnchoredParts;
	}

	bool DebugSettings::getShowUnalignedParts() const
	{
		return PartInstance::showUnalignedParts;
	}

	bool DebugSettings::getShowPartCoordinateFrames() const
	{
		return PartInstance::showPartCoord;
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	bool DebugSettings::getShowModelCoordinateFrames() const
	{
		return ModelInstance::showModelCoord;
	}
#endif

	void DebugSettings::setShowAnchoredParts(bool value)
	{
		if (value != PartInstance::showAnchoredParts)
		{
			PartInstance::showAnchoredParts = value;
			raisePropertyChanged(prop_ShowAnchors);
		}
	}

	void DebugSettings::setShowUnalignedParts(bool value)
	{
		if (value != PartInstance::showUnalignedParts)
		{
			PartInstance::showUnalignedParts = value;
			raisePropertyChanged(prop_ShowPartCoords); // 00565c20 pushes prop_ShowPartCoords (009745dc), as the donor
		}
	}

	void DebugSettings::setShowPartCoordinateFrames(bool value)
	{
		if (value != PartInstance::showPartCoord)
		{
			PartInstance::showPartCoord = value;
			raisePropertyChanged(prop_ShowPartCoords);
		}
	}

	void DebugSettings::setShowModelCoordinateFrames(bool value)    // 00565c80
	{
		if (value != ModelInstance::showModelCoord)
		{
			ModelInstance::showModelCoord = value;
			raisePropertyChanged(prop_ShowModelCoords);
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
			raisePropertyChanged(prop_AssertAction);
		}
	}

#ifdef NATIVE_DEBUGSETTINGS_PENDING
	World::EThrottle DebugSettings::getEnvironmentalThrottle() const
	{
		return World::environmentalThrottle;
	}

	void DebugSettings::setEnvironmentalThrottle(World::EThrottle value)
	{
		if (value != World::environmentalThrottle)
		{
			World::environmentalThrottle = value;
			raisePropertyChanged(prop_PhysicsEnviromentalThrottle);
		}
	}
#endif

	void DebugSettings::setErrorReporting(ErrorReporting value)
	{
		if (value != errorReporting)
		{
			errorReporting = value;
			raisePropertyChanged(prop_ErrorReporting);
		}
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::DebugSettings::ErrorReporting>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Debugable::AssertAction>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0> >;
template class std::_Vector_const_iterator<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Vector_const_iterator<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::_Vector_iterator<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::_Vector_iterator<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::DebugSettings::ErrorReporting,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Debugable::AssertAction,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::DebugSettings::ErrorReporting> >;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::Debugable::AssertAction> >;
template class std::vector<enum RBX::DebugSettings::ErrorReporting,std::allocator<enum RBX::DebugSettings::ErrorReporting> >;
template class std::vector<enum RBX::Debugable::AssertAction,std::allocator<enum RBX::Debugable::AssertAction> >;

template void RBX::Name::callDoDeclare<RBX::sDebugSettings>();

namespace RBX
{
float DebugSettings::shaderModel() const
{
	return Render::SpecData().shaderModel;
}
}

namespace RBX
{
int DebugSettings::ram(void) const
{
	return RBX::Render::SpecData().ram;
}
}

namespace RBX
{
int DebugSettings::cpuSpeed() const
{
	return Render::SpecData().CPUSpeed;
}
}

namespace RBX
{
int DebugSettings::cpuCount() const
{
	return Render::SpecData().cpuCount;
}
}

namespace RBX
{
int DebugSettings::videoMemory() const
{
	return Render::SpecData().videoMemory;
}
}

#include <G3D/RegistryUtil.h>
#include <windows.h>
#include <setupapi.h>
#include <cstring>

namespace RBX
{
std::string DebugSettings::gfxcard() const     // 005634b0
	{
		DISPLAY_DEVICEA display;
		memset(&display, 0, sizeof(display));
		display.cb = sizeof(display);
		EnumDisplayDevicesA(NULL, 0, &display, 0);
		SP_CLASSIMAGELIST_DATA images;
		memset(&images, 0, sizeof(images));
		SetupDiDestroyClassImageList(&images);
		images = SP_CLASSIMAGELIST_DATA();
		images.cbSize = sizeof(images);
		SetupDiGetClassImageList(&images);
		SP_DEVINFO_DATA device = {0};
		char name[64] = {0};
		HDEVINFO devices = SetupDiGetClassDevsA(NULL, NULL, NULL, DIGCF_PROFILE | DIGCF_ALLCLASSES | DIGCF_PRESENT);
		if (devices == INVALID_HANDLE_VALUE)
			return "";
		short index = 0;
		device.cbSize = sizeof(device);
		while (SetupDiEnumDeviceInfo(devices, index, &device))
		{
			char className[MAX_PATH] = "";
			int imageIndex = 0;
			DWORD required;
			if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_CLASS, NULL, reinterpret_cast<PBYTE>(className), MAX_PATH - 1, NULL)
				&& SetupDiGetClassImageIndex(&images, &device.ClassGuid, &imageIndex)
				&& SetupDiGetClassDescriptionA(&device.ClassGuid, className, MAX_PATH, &required))
			{
				if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_FRIENDLYNAME, NULL, reinterpret_cast<PBYTE>(name), 63, NULL))
				{
					if (strcmp(name, display.DeviceString) == 0)
						break;
				}
				else if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_DEVICEDESC, NULL, reinterpret_cast<PBYTE>(name), 63, NULL))
				{
					if (strcmp(name, display.DeviceString) == 0)
						break;
				}
			}
			++index;
		}
		std::string driverKey("unknown");
		char driver[64] = {0};
		device.cbSize = sizeof(device);
		if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_DRIVER, NULL, reinterpret_cast<PBYTE>(driver), 63, NULL))
			driverKey = driver;
		std::string version("?");
		G3D::RegistryUtil::readString(
			"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\" + driverKey + "\\DriverVersion",
			version);
		return std::string(display.DeviceString) + " drv=" + version;
	}
}

namespace RBX
{
std::string DebugSettings::systemProductName() const // 00563370
	{
		std::string name;
		if (G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\BIOS\\SystemProductName", name))
			return name;
		else
			return "?";
	}
}

namespace RBX
{
int DebugSettings::osPlatformId() const        // 00563330
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return osvi.dwPlatformId;
	}
}

namespace RBX
{
std::string DebugSettings::osVer() const       // 005632c0
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return G3D::format("%d.%d.%d.%d", osvi.dwOSVersionInfoSize, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
	}
}

#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
#ifndef NATIVE_DEBUGSETTINGS_PENDING
bool DebugSettings::getShowModelCoordinateFrames() const
{
	return ModelInstance::showModelCoord;
}
#endif

bool DebugSettings::getShowWorldCoordinateFrames() const
{
	return Workspace::showWorldCoord;
}
}
