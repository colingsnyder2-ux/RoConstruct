// from server: 35% by Intel
struct EnumDesc {
    void Initialize();
};

extern "C" void __stdcall __security_cookie_init(int);
extern "C" void __cdecl _initterm(void*, void*);
extern "C" void __stdcall _atexit(void(*)());

void EnumDesc::Initialize() {
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        char buffer[16];
        *(int*)buffer = 0;
        *(int*)(buffer + 4) = 0;
        *(int*)(buffer + 8) = 27;
        int value = *(int*)0xBBF9C4;
        int result = ((int(__thiscall*)(int, char*))0x52A9C0)(value, buffer);
        ((void(__thiscall*)(int, int))0x6CAB60)(0xE3AE20, result);
        _atexit((void(*)())0xB1B2D0);
    }
}
