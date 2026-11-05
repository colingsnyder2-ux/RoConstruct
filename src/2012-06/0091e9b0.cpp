// from server: 75% by Intel
typedef unsigned long DWORD;
typedef void* LPVOID;

extern "C" void __stdcall InitializeCriticalSection(LPVOID lpCriticalSection);
extern "C" void __cdecl sub_9831f5(DWORD);

DWORD g_initFlag = 0;
DWORD g_criticalSection = 0xE56B44;
DWORD g_unk1 = 0xE56B5C;
DWORD g_unk2 = 0xE56B60;
DWORD g_unk3 = 0xE56B64;
DWORD g_unk4 = 0xE56B68;
DWORD g_unk5 = 0xE56B6C;
DWORD g_unk6 = 0xE56B70;
DWORD g_initializeCriticalSectionPtr = 0xB221DC;
DWORD g_sub9831f5Param = 0xB21300;

DWORD* GetMotorJointCriticalSection() {
    if (g_initFlag & 1) {
        return (DWORD*)g_criticalSection;
    }

    g_initFlag |= 1;

    typedef void (__stdcall *InitCritSecFn)(LPVOID);
    ((InitCritSecFn)g_initializeCriticalSectionPtr)((LPVOID)g_criticalSection);

    g_unk1 = 0;
    g_unk2 = 0;
    g_unk3 = 0;

    g_unk4 = 0xD0;
    g_unk5 = 0x20;
    g_unk6 = 0x20;

    sub_9831f5(g_sub9831f5Param);

    return (DWORD*)g_criticalSection;
}
