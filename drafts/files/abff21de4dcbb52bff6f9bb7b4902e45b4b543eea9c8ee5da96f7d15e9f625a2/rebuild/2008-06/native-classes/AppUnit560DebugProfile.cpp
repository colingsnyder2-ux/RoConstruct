// 2008-06 native RBX::DebugSettings "Profile" getters (inactive), the v8datamodel/DebugSettings.cpp rows
// 005631c0..00563a76 of the application range 00560000..00564000. The class and its getter declarations are the
// committed native-headers/v8datamodel/DebugSettings.h; RBX::Render::SpecData (0x84 bytes) is the committed
// native-headers/AppUnit500/RenderSpecData.h. Both are included read-only. Verified by
// tests/record_native_app_unit560.py (document-swap flags, VS2008 RTM 21022).
//
// Evidence (target bytes):
//   every SpecData getter reserves `sub esp, 0x84` (sizeof SpecData), constructs it with 00501ae0 and destroys it
//   with the implicit destructor 005631c0 (strings at +0x68, +0x48, +0x2c, +0x10 through the msvcp90 import);
//   the int getters read +0x4 / +0x8 / +0xc / +0x64 (00563230 / 00563260 / 00563290 / 00563940), the string getters
//   copy +0x10 / +0x48 / +0x68 (00563430 / 005638c0 / 00563970), shaderModel loads +0x0 (00563a50);
//   osVer 005632c0 / osPlatformId 00563330: memset(&osvi + 4, 0, 0x90), dwOSVersionInfoSize = 0x94,
//   GetVersionExA, then G3D::format("%d.%d.%d.%d" 0081cf30, ...) / dwPlatformId;
//   systemProductName 00563370: G3D::RegistryUtil::readString 00514190 of
//   "HKEY_LOCAL_MACHINE\HARDWARE\DESCRIPTION\System\BIOS\SystemProductName" (0082dfc8), "?" (00819e10) otherwise;
//   gfxcard 005634b0: EnumDisplayDevicesA with a 0x1a8-byte DISPLAY_DEVICEA, a 0xc-byte SP_CLASSIMAGELIST_DATA and a
//   0x1c-byte SP_DEVINFO_DATA (cbSize stores), SetupDiGetClassDevsA(NULL, NULL, NULL, 0xe), the SPDRP_CLASS (7) /
//   SPDRP_FRIENDLYNAME (0xc) / SPDRP_DEVICEDESC (0) / SPDRP_DRIVER (9) property reads (0x103 / 0x3f buffer limits),
//   the device index as a short (movsx edx, di), "unknown" 0082e064, the class key 0082e028 + "\DriverVersion"
//   0082e018 read with RegistryUtil::readString, and DeviceString + " drv=" 0082e010 + version. The body shape is the
//   matched server analog of this row (rbxgs-dll unit roc_unit_09f8f9973c494ab8.cpp, by colin).
#include "v8datamodel/DebugSettings.h"
#include "AppUnit500/RenderSpecData.h"
#include <G3D/RegistryUtil.h>
#include <G3D/format.h>
#include <windows.h>
#include <setupapi.h>
#include <cstring>

namespace RBX
{
	float DebugSettings::shaderModel() const       // 00563a50
	{
		return Render::SpecData().shaderModel;
	}

	int DebugSettings::videoMemory() const         // 00563230
	{
		return Render::SpecData().videoMemory;
	}

	int DebugSettings::cpuSpeed() const            // 00563260
	{
		return Render::SpecData().CPUSpeed;
	}

	int DebugSettings::cpuCount() const            // 00563290
	{
		return Render::SpecData().cpuCount;
	}

	std::string DebugSettings::glVendor() const    // 00563430
	{
		return Render::SpecData().glVendor;
	}

	std::string DebugSettings::cpu() const         // 005638c0
	{
		return Render::SpecData().cpu;
	}

	int DebugSettings::ram() const                 // 00563940
	{
		return Render::SpecData().ram;
	}

	std::string DebugSettings::resolution() const  // 00563970
	{
		return Render::SpecData().resolution;
	}

	std::string DebugSettings::osVer() const       // 005632c0
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return G3D::format("%d.%d.%d.%d", osvi.dwOSVersionInfoSize, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
	}

	int DebugSettings::osPlatformId() const        // 00563330
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return osvi.dwPlatformId;
	}

	std::string DebugSettings::systemProductName() const // 00563370
	{
		std::string name;
		if (G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\BIOS\\SystemProductName", name))
			return name;
		else
			return "?";
	}

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
		G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\" + driverKey + "\\DriverVersion", version);
		return std::string(display.DeviceString) + " drv=" + version;
	}
}
