// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_09f8f9973c494ab8.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#include "G3D/platform.h"
#include <windows.h>
#include <setupapi.h>
#include <cstring>
#include <string>
#include "G3D/RegistryUtil.h"

#include "v8datamodel/DebugSettings.h"

std::string RBX::DebugSettings::gfxcard() const
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
    while (SetupDiEnumDeviceInfo(devices, index, &device)) {
        char className[MAX_PATH] = "";
        int imageIndex = 0;
        DWORD required;
        if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_CLASS, NULL,
                reinterpret_cast<PBYTE>(className), MAX_PATH-1, NULL)
            && SetupDiGetClassImageIndex(&images, &device.ClassGuid, &imageIndex)
            && SetupDiGetClassDescriptionA(&device.ClassGuid, className, MAX_PATH, &required)) {
            if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_FRIENDLYNAME, NULL,
                    reinterpret_cast<PBYTE>(name), 63, NULL)) {
                if (strcmp(name, display.DeviceString) == 0)
                    break;
            } else if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_DEVICEDESC, NULL,
                    reinterpret_cast<PBYTE>(name), 63, NULL)) {
                if (strcmp(name, display.DeviceString) == 0)
                    break;
            }
        }
        ++index;
    }
    std::string driverKey("unknown");
    char driver[64] = {0};
    device.cbSize = sizeof(device);
    if (SetupDiGetDeviceRegistryPropertyA(devices, &device, SPDRP_DRIVER, NULL,
            reinterpret_cast<PBYTE>(driver), 63, NULL))
        driverKey = driver;
    std::string version("?");
    G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\" + driverKey + "\\DriverVersion", version);
    return std::string(display.DeviceString) + " drv=" + version;
}
