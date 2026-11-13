// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AppUnit560DebugProfile | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 475546b2 | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include "AppUnit500/RenderSpecData.h"
#include <G3D/RegistryUtil.h>
#include <G3D/format.h>
#include <windows.h>
#include <setupapi.h>
#include <cstring>
namespace RBX {
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

namespace RBX {
std::string DebugSettings::systemProductName() const // 00563370
	{
		std::string name;
		if (G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\BIOS\\SystemProductName", name))
			return name;
		else
			return "?";
	}
}

namespace RBX {
int DebugSettings::osPlatformId() const        // 00563330
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return osvi.dwPlatformId;
	}
}

namespace RBX {
std::string DebugSettings::osVer() const       // 005632c0
	{
		OSVERSIONINFOA osvi;
		ZeroMemory((char*)&osvi + sizeof(DWORD), sizeof(OSVERSIONINFOA) - sizeof(DWORD));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

		GetVersionExA(&osvi);

		return G3D::format("%d.%d.%d.%d", osvi.dwOSVersionInfoSize, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
	}
}
