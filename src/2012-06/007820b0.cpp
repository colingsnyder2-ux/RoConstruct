// from server: 38% by Intel
struct EnumDesc {
    void Initialize();
};

extern "C" void __stdcall InitializeCriticalSection(void* lpCriticalSection);
extern "C" void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" void __stdcall LeaveCriticalSection(void* lpCriticalSection);
extern "C" int __cdecl atexit(void (__cdecl*)(void));

void EnumDesc::Initialize() {
    static int initialized = 0;
    if (!initialized) {
        initialized = 1;
        char buffer[16];
        *(int*)buffer = 0;
        *(int*)(buffer + 4) = 0;
        *(int*)(buffer + 8) = 0;
        *(int*)(buffer + 12) = 27;
        int value = *(int*)0xBEC988;
        InitializeCriticalSection((void*)0xE44A70);
        EnterCriticalSection((void*)0xE44A70);
        atexit((void (__cdecl*)(void))0xB1ADB0);
        LeaveCriticalSection((void*)0xE44A70);
    }
}
