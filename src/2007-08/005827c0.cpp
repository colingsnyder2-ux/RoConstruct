// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/DebugSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebugSettings.h"

#include "reflection/property.h"
#include "renderlib/Profiler.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

#include <G3D/RegistryUtil.h>
#include <G3D/format.h>
#include <setupapi.h>
#include <windows.h>

namespace RBX {

const char sDebugSettings[] = "DebugSettings";

} // namespace RBX

using namespace RBX;
using namespace RBX::Reflection;

static PropDescriptor<DebugSettings, float> prop_shaderModel("ShaderModel", "Profile", &DebugSettings::shaderModel, 0);
static PropDescriptor<DebugSettings, int> prop_videoMemory("VideoMemory", "Profile", &DebugSettings::videoMemory, 0);
static PropDescriptor<DebugSettings, int> prop_cpuSpeed("CpuSpeed", "Profile", &DebugSettings::cpuSpeed, 0);
static PropDescriptor<DebugSettings, int> prop_osPlatformId("OsPlatformId", "Profile", &DebugSettings::osPlatformId, 0);
static PropDescriptor<DebugSettings, std::string> prop_osVer("OsVer", "Profile", &DebugSettings::osVer, 0);
static PropDescriptor<DebugSettings, std::string> prop_glVendor("GlVendor", "Profile", &DebugSettings::glVendor, 0);
static PropDescriptor<DebugSettings, std::string> prop_gfxcard("GfxCard", "Profile", &DebugSettings::gfxcard, 0);
static PropDescriptor<DebugSettings, std::string> prop_cpu("CPU", "Profile", &DebugSettings::cpu, 0);
static PropDescriptor<DebugSettings, int> prop_ram("RAM", "Profile", &DebugSettings::ram, 0);
static PropDescriptor<DebugSettings, std::string> prop_resolution(
	"Resolution", "Profile", &DebugSettings::resolution, 0
);

BoundProp<bool, 1> prop_SoundWarnings("SoundWarnings", "Errors", &DebugSettings::soundWarnings);

BoundProp<bool, 1> DebugSettings::prop_stackTracingEnabled(
	"stackTracingEnabled", "Scripts", &DebugSettings::stackTracingEnabled
);

BoundProp<bool, 1> DebugSettings::prop_ioEnabled(
	"ioEnabled", "Scripts", &DebugSettings::ioEnabled, PropertyDescriptor::STREAMING
);

static PropDescriptor<DebugSettings, bool> prop_AnchoredParts(
	"ShowAnchors", "Display", &DebugSettings::getShowAnchoredParts, &DebugSettings::setShowAnchoredParts
);

static PropDescriptor<DebugSettings, bool> prop_PartCoordinateFrames(
	"ShowPartCoords",
	"Display",
	&DebugSettings::getShowPartCoordinateFrames,
	&DebugSettings::setShowPartCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_UnalignedParts(
	"ShowUnalignedParts", "Display", &DebugSettings::getShowUnalignedParts, &DebugSettings::setShowUnalignedParts
);

static PropDescriptor<DebugSettings, bool> prop_ModelCoordinateFrames(
	"ShowModelCoords",
	"Display",
	&DebugSettings::getShowModelCoordinateFrames,
	&DebugSettings::setShowModelCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_WorldCoordinateFrames(
	"ShowWorldCoords",
	"Display",
	&DebugSettings::getShowWorldCoordinateFrames,
	&DebugSettings::setShowWorldCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_DisableEnvironmentalThrottle(
	"DisableEnvironmentalThrottle",
	"Display",
	&DebugSettings::getDisableEnvironmentalThrottle,
	&DebugSettings::setDisableEnvironmentalThrottle
);

static PropDescriptor<DebugSettings, bool> prop_ValidatingDebug(
	"ValidatingDebug", "Errors", &DebugSettings::getValidatingDebug, &DebugSettings::setValidatingDebug
);

static EnumPropDescriptor<DebugSettings, Debugable::AssertAction> prop_assertAction(
	"AssertAction", "Errors", &DebugSettings::getAssertAction, &DebugSettings::setAssertAction
);

static EnumPropDescriptor<DebugSettings, DebugSettings::ErrorReporting> prop_errorReporting(
	"errorReporting", "Errors", &DebugSettings::getErrorReporting, &DebugSettings::setErrorReporting
);

namespace RBX {

// FUNCTION: WEBSERVICE 0x100b2d30
bool DebugSettings::getValidatingDebug() const
{
	return Debugable::validatingDebug;
}

// FUNCTION: WEBSERVICE 0x100b2d40
Debugable::AssertAction DebugSettings::getAssertAction() const
{
	return Debugable::assertAction;
}

// FUNCTION: WEBSERVICE 0x100b2d60
bool DebugSettings::getShowAnchoredParts() const
{
	return PartInstance::showAnchoredParts;
}

// FUNCTION: WEBSERVICE 0x100b2d70
bool DebugSettings::getShowUnalignedParts() const
{
	return PartInstance::showUnalignedParts;
}

// FUNCTION: WEBSERVICE 0x100b2d80
bool DebugSettings::getShowPartCoordinateFrames() const
{
	return PartInstance::showPartCoord;
}

// FUNCTION: WEBSERVICE 0x100b2d90
bool DebugSettings::getShowModelCoordinateFrames() const
{
	return ModelInstance::showModelCoord;
}

// FUNCTION: WEBSERVICE 0x100b2da0
bool DebugSettings::getShowWorldCoordinateFrames() const
{
	return Workspace::showWorldCoord;
}

// FUNCTION: WEBSERVICE 0x100b2db0
bool DebugSettings::getDisableEnvironmentalThrottle() const
{
	return World::disableEnvironmentalThrottle;
}

// FUNCTION: WEBSERVICE 0x100b2e30
// FUNCTION: ROBLOX 0x0057ac10
int DebugSettings::videoMemory() const
{
	return Render::SpecData().videoMemory;
}

// FUNCTION: WEBSERVICE 0x100b2e60
// FUNCTION: ROBLOX 0x0057ac40
int DebugSettings::cpuSpeed() const
{
	return Render::SpecData().CPUSpeed;
}

// FUNCTION: WEBSERVICE 0x100b2e90
// FUNCTION: ROBLOX 0x0057ac70
std::string DebugSettings::osVer() const
{
	OSVERSIONINFO osvi = {0};

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	return G3D::format(
		"%d.%d.%d.%d", osvi.dwOSVersionInfoSize, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber
	);
}

// FUNCTION: WEBSERVICE 0x100b2f00
// FUNCTION: ROBLOX 0x0057ace0
int DebugSettings::osPlatformId() const
{
	OSVERSIONINFO osvi = {0};

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	return osvi.dwPlatformId;
}

// FUNCTION: WEBSERVICE 0x100b2f40
// FUNCTION: ROBLOX 0x0057ad20
std::string DebugSettings::glVendor() const
{
	return Render::SpecData().glVendor;
}

// STUB: WEBSERVICE 0x100b2fc0
// STUB: ROBLOX 0x0057ada0
std::string DebugSettings::gfxcard() const
{
	DISPLAY_DEVICE displayDevice;
	memset(&displayDevice, 0, sizeof(displayDevice));
	displayDevice.cb = sizeof(displayDevice);
	EnumDisplayDevices(NULL, 0, &displayDevice, 0);

	SP_CLASSIMAGELIST_DATA _spImageData = {0};
	SetupDiDestroyClassImageList(&_spImageData);
	ZeroMemory(&_spImageData, sizeof(SP_CLASSIMAGELIST_DATA));
	_spImageData.cbSize = sizeof(SP_CLASSIMAGELIST_DATA);
	SetupDiGetClassImageList(&_spImageData);

	SP_DEVINFO_DATA spDevInfoData = {0};
	char szName[64] = {0};

	HDEVINFO hDevInfo = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES | DIGCF_PROFILE);
	if (hDevInfo == INVALID_HANDLE_VALUE) {
		return "";
	}

	short wIndex = 0;
	spDevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	while (SetupDiEnumDeviceInfo(hDevInfo, wIndex, &spDevInfoData)) {
		char szBuf[MAX_PATH] = {0};
		int wImageIdx = 0;

		if (SetupDiGetDeviceRegistryProperty(
				hDevInfo, &spDevInfoData, SPDRP_CLASS, NULL, (PBYTE) szBuf, MAX_PATH - 1, NULL
			)) {
			if (SetupDiGetClassImageIndex(&_spImageData, &spDevInfoData.ClassGuid, &wImageIdx)) {
				DWORD dwRequireSize;
				if (SetupDiGetClassDescription(&spDevInfoData.ClassGuid, szBuf, MAX_PATH, &dwRequireSize)) {
					if (SetupDiGetDeviceRegistryProperty(
							hDevInfo, &spDevInfoData, SPDRP_FRIENDLYNAME, NULL, (PBYTE) szName, 63, NULL
						)) {
						if (strcmp(szName, displayDevice.DeviceString) == 0) {
							break;
						}
					}
					else if (
						SetupDiGetDeviceRegistryProperty(
							hDevInfo, &spDevInfoData, SPDRP_DEVICEDESC, NULL, (PBYTE) szName, 63, NULL
						)
					) {
						if (strcmp(szName, displayDevice.DeviceString) == 0) {
							break;
						}
					}
				}
			}
		}

		wIndex++;
	}

	std::string deviceKey = "unknown";

	char buf[64] = {0};
	spDevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	if (SetupDiGetDeviceRegistryProperty(hDevInfo, &spDevInfoData, SPDRP_DRIVER, NULL, (PBYTE) buf, 63, NULL)) {
		deviceKey = buf;
	}

	std::string driverVersion = "?";
	G3D::RegistryUtil::readString(
		"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\" + deviceKey + "\\DriverVersion", driverVersion
	);

	return std::string(displayDevice.DeviceString) + " drv=" + driverVersion;
}

// FUNCTION: WEBSERVICE 0x100b33d0
// FUNCTION: ROBLOX 0x0057b1b0
std::string DebugSettings::cpu() const
{
	return Render::SpecData().cpu;
}

// FUNCTION: WEBSERVICE 0x100b3450
// FUNCTION: ROBLOX 0x0057b230
int DebugSettings::ram() const
{
	return Render::SpecData().ram;
}

// FUNCTION: WEBSERVICE 0x100b3480
// FUNCTION: ROBLOX 0x0057b260
std::string DebugSettings::resolution() const
{
	return Render::SpecData().resolution;
}

// FUNCTION: WEBSERVICE 0x100b3610
// FUNCTION: ROBLOX 0x0057b350
float DebugSettings::shaderModel() const
{
	return Render::SpecData().shaderModel;
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x100b3f40
// FUNCTION: ROBLOX 0x0057bf40
template <>
EnumDesc<DebugSettings::ErrorReporting>::EnumDesc()
	: EnumDescriptor("ErrorReporting", typeid(DebugSettings::ErrorReporting))
{
	addPair(DebugSettings::DontReport, "DontReport");
	addPair(DebugSettings::Prompt, "Prompt");
	addPair(DebugSettings::Report, "Report");
}

// FUNCTION: WEBSERVICE 0x100b40c0
// FUNCTION: ROBLOX 0x0057c0c0
template <>
EnumDesc<Debugable::AssertAction>::EnumDesc() : EnumDescriptor("AssertAction", typeid(Debugable::AssertAction))
{
	addPair(Debugable::CrashOnAssert, "CrashOnAssert");
	addPair(Debugable::IgnoreAssert, "IgnoreAssert");
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x100b5090
// FUNCTION: ROBLOX 0x0057d040
DebugSettings::DebugSettings()
	: stackTracingEnabled(true), ioEnabled(false), soundWarnings(false), errorReporting(Prompt)
{
	setName("Diagnostics");
}

// FUNCTION: WEBSERVICE 0x100b51f0
void DebugSettings::setShowAnchoredParts(bool value)
{
	if (value != PartInstance::showAnchoredParts) {
		PartInstance::showAnchoredParts = value;
		raisePropertyChanged(prop_AnchoredParts);
	}
}

// FUNCTION: WEBSERVICE 0x100b5220
void DebugSettings::setShowUnalignedParts(bool value)
{
	if (value != PartInstance::showUnalignedParts) {
		PartInstance::showUnalignedParts = value;
		raisePropertyChanged(prop_PartCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b5250
void DebugSettings::setShowPartCoordinateFrames(bool value)
{
	if (value != PartInstance::showPartCoord) {
		PartInstance::showPartCoord = value;
		raisePropertyChanged(prop_PartCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b5280
void DebugSettings::setShowModelCoordinateFrames(bool value)
{
	if (value != ModelInstance::showModelCoord) {
		ModelInstance::showModelCoord = value;
		raisePropertyChanged(prop_ModelCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b52b0
void DebugSettings::setShowWorldCoordinateFrames(bool value)
{
	if (value != Workspace::showWorldCoord) {
		Workspace::showWorldCoord = value;
		raisePropertyChanged(prop_WorldCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b52e0
void DebugSettings::setDisableEnvironmentalThrottle(bool value)
{
	if (value != World::disableEnvironmentalThrottle) {
		World::disableEnvironmentalThrottle = value;
		raisePropertyChanged(prop_DisableEnvironmentalThrottle);
	}
}

// FUNCTION: WEBSERVICE 0x100b5310
void DebugSettings::setValidatingDebug(bool value)
{
	if (value != Debugable::validatingDebug) {
		Debugable::validatingDebug = value;
		raisePropertyChanged(prop_ValidatingDebug);
	}
}

// FUNCTION: WEBSERVICE 0x100b5340
void DebugSettings::setAssertAction(Debugable::AssertAction value)
{
	if (value != Debugable::assertAction) {
		Debugable::assertAction = value;
		raisePropertyChanged(prop_assertAction);
	}
}

// FUNCTION: WEBSERVICE 0x100b5370
void DebugSettings::setErrorReporting(ErrorReporting value)
{
	if (value != errorReporting) {
		errorReporting = value;
		raisePropertyChanged(prop_errorReporting);
	}
}
} // namespace RBX
