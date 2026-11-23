// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <intrin.h>

// INFERRED: G3D::System statics (G3D 6.09 System.cpp), file-local stand-ins
static bool g_initialized;
static char g_version[0x100];
static bool g_rdtsc;
static int g_cpuIdMax;
static int g_cpuIdVendor[3];
static int g_cpuFamily;
static int g_cpuExt;
static char g_cpuArch[0x100];
static char g_osVersion[0x100];
static int g_one;

extern "C" void fn_00507990();   // G3D::initTime
extern "C" void fn_00507840();   // G3D::getStandardProcessorExtensions

extern "C" void fn_00508110()
{
    if (g_initialized) return;
    g_initialized = true;
    sprintf(g_version, "G3D %d.%02d", 6, 9);

    int info[4] = {0, 0, 0, 0};
    // INFERRED: original used __asm pushfd/cpuid; intrinsic used (no inline asm allowed here)
    __cpuid(info, 0);
    g_one = 1;
    g_rdtsc = info[0] != 0;

    if (g_rdtsc) {
        g_cpuIdVendor[0] = info[1];
        g_cpuIdVendor[1] = info[3];
        g_cpuIdVendor[2] = info[2];
        g_cpuFamily = info[0] & 0xffff;
        __cpuid(info, 0x80000000);
        g_cpuExt = info[0];
        if (info[1] == 0x68747541)
            strcpy(g_cpuArch, "AMD Processor");
        else if (info[1] == 0x69727943)
            strcpy(g_cpuArch, "Cyrix Processor");
        else if (info[1] == 0x756e6547)
            strcpy(g_cpuArch, "Intel Processor");
        else
            strcpy(g_cpuArch, "Unknown Processor Vendor");
    }

    SYSTEM_INFO si;
    GetSystemInfo(&si);
    const char* arch;
    switch (si.wProcessorArchitecture) {
    case 0: arch = "Intel"; break;
    case 1: arch = "MIPS"; break;
    case 2: arch = "Alpha"; break;
    case 3: arch = "Power PC"; break;
    default: arch = "Unknown"; break;
    }
    double n = (double)si.dwNumberOfProcessors;
    sprintf(g_cpuArch, "%d x %d-bit %s processor", si.dwNumberOfProcessors,
            (int)(log(n) / log(2.0) + 0.5), arch);

    OSVERSIONINFOA vi;
    vi.dwOSVersionInfoSize = sizeof(vi);
    if (GetVersionExA(&vi))
        sprintf(g_osVersion, "Windows %d.%d build %d Platform %d %s",
                vi.dwMajorVersion, vi.dwMinorVersion, vi.dwBuildNumber,
                vi.dwPlatformId, vi.szCSDVersion);
    else
        strcpy(g_osVersion, "Windows");

    fn_00507990();
    fn_00507840();
}
