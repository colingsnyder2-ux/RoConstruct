// from server: 85% by Intel
extern "C" void __stdcall InitializeCriticalSection(void* lpCriticalSection);
extern "C" void __cdecl sub_9831f5(void*);

struct CriticalSection {
    char data[24];
};

CriticalSection g_criticalSection;
int g_dword_E51250;
int g_dword_E51254;
int g_dword_E51258;
int g_dword_E5125C;
int g_dword_E51260;
int g_dword_E51264;
int g_dword_E51268;
int g_ptr_B1EB50;

void* __cdecl sub_82B6C0() {
    int eax = 1;
    if (reinterpret_cast<char&>(g_dword_E51268) & 1) {
        return &g_criticalSection;
    }
    g_dword_E51268 |= eax;
    InitializeCriticalSection(&g_criticalSection);
    eax = 0;
    g_dword_E51250 = eax;
    g_dword_E51254 = eax;
    g_dword_E51258 = eax;
    eax = 0x20;
    sub_9831f5(reinterpret_cast<void*>(0xB1EB50));
    g_dword_E5125C = 0xE4;
    g_dword_E51260 = eax;
    g_dword_E51264 = eax;
    return &g_criticalSection;
}
