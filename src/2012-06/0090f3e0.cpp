// from server: 59% by Intel
extern "C" void __stdcall InitializeCriticalSection(void* lpCriticalSection);

void __cdecl sub_9831f5(int);

struct RightAngleRampPoly {
    static void* Initialize();
};

void* RightAngleRampPoly::Initialize() {
    static unsigned char initialized = 0;
    static char criticalSection[24];
    static int dword_E569E0 = 0;
    static int dword_E569E4 = 0;
    static int dword_E569E8 = 0;
    static int dword_E569EC = 0;
    static int dword_E569F0 = 0;
    static int dword_E569F4 = 0;

    if (!initialized) {
        initialized = 1;
        InitializeCriticalSection(criticalSection);
        dword_E569E0 = 0;
        dword_E569E4 = 0;
        dword_E569E8 = 0;
        dword_E569EC = 0x3C;
        dword_E569F0 = 0x20;
        dword_E569F4 = 0x20;
        sub_9831f5(0xB211B0);
    }
    return criticalSection;
}
