// from server: 53% by colin
struct CMainFrame {
    unsigned char pad0[0xdc];
    void* field_dc;
    unsigned char pad_e0[0x10];
    void* field_f0;
    unsigned char pad_f4[0x2c];
    void* field_120;
    unsigned char pad_124[0x148];
    void* field_26c;
    unsigned char pad_270[0x120];
    void* field_390;
    void* field_394;
    void* field_398;
    void* field_39c;
    unsigned char pad_3a0[0x28];
    void* field_3c8;
    CMainFrame();
};

extern "C" void __stdcall sub_66AB40();
extern "C" void __stdcall sub_66DBB0();
extern "C" void __stdcall sub_66FCD0();
extern "C" void __stdcall sub_68ACC0();
extern "C" void __stdcall sub_691E80();
extern "C" void __stdcall sub_692B00();
extern "C" void __stdcall sub_66E080();
extern "C" void __stdcall sub_423240();
extern "C" void __stdcall sub_64DFD0();
extern "C" void __stdcall sub_630A1E();

extern "C" long __stdcall RegOpenKeyExA(void*, const char*, unsigned long, unsigned long, void**);
extern "C" long __stdcall RegQueryValueExA(void*, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);
extern "C" long __stdcall RegCloseKey(void*);
extern "C" long __stdcall SHGetFolderPathAndSubDirA(void*, int, void*, unsigned long, const char*, char*);
extern "C" long __stdcall InterlockedIncrement(long*);

extern void* g_77ddac;
extern void* g_77dd94;
extern void* g_77d2ec;
extern void* g_77ebc4;
extern void* g_77d010;
extern void* g_77d020;
extern void* g_77d008;

extern unsigned char g_8bb915;
extern unsigned char g_8c30f5;

CMainFrame::CMainFrame()
{
    sub_66AB40();
    field_dc = (void*)0x78a710;
    field_f0 = 0;
    *(void**)this = (void*)0x78b4fc;
    field_dc = (void*)0x78b4f0;
    *(unsigned char*)((char*)this + 0xe0) = 0;
    *(unsigned char*)((char*)this + 0xe1) = 0;
    *(unsigned long*)((char*)this + 0xe4) = 0;
    *(unsigned long*)((char*)this + 0xe8) = 0;
    *(unsigned char*)((char*)this + 0xec) = 0;
    *(unsigned char*)((char*)this + 0xed) = 0;
    ((void (__stdcall*)())g_77ddac)();
    sub_66DBB0();
    sub_66FCD0();
    sub_68ACC0();
    field_390 = 0;
    field_394 = 0;
    field_398 = 0;
    sub_691E80();
    sub_692B00();

    void* hkey = 0;
    unsigned long type = 0;
    unsigned long size = 0;
    unsigned char buf[4];
    *(unsigned long*)buf = 0;
    if (RegOpenKeyExA((void*)0x80000001, "Software\\ROBLOX Corporation\\Roblox", 0, 0x20019, &hkey) == 0)
    {
        size = 4;
        RegQueryValueExA(hkey, "OverrideLockViewGamelayout", 0, &type, buf, &size);
    }
    unsigned char v = (*(unsigned long*)buf == 1);
    g_8bb915 = v;
    g_8c30f5 = v;
    if (hkey)
        RegCloseKey(hkey);

    char path[260];
    if (SHGetFolderPathAndSubDirA(0, 0x801a, 0, 0, "\\ROBLOX", path) == 0)
    {
        char full[260];
        sub_423240();
        sub_64DFD0();
        sub_66E080();
    }
}
