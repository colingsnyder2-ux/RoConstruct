// from server: 30% by Intel
typedef unsigned long DWORD;

struct EnumDesc {
    void init();
};

extern "C" void __cdecl _initterm(void*, void*);
extern "C" void __stdcall _onexit(void (__cdecl*)());
extern "C" int __cdecl _atexit(void (__cdecl*)());

void EnumDesc::init() {
    static int initialized = 0;
    if (!initialized) {
        initialized = 1;
        int v = 0;
        char buf[12];
        *(DWORD*)&buf[0] = 0;
        *(DWORD*)&buf[4] = 0;
        *(DWORD*)&buf[8] = 0x1B;
        DWORD* ptr = *(DWORD**)0xBC0BBC;
        int (__cdecl *func1)(DWORD*, char*) = (int (__cdecl*)(DWORD*, char*))0x4125D0;
        int result = func1(ptr, buf);
        void (__thiscall *func2)(int, int) = (void (__thiscall*)(int, int))0x6CAB60;
        func2(result, 0);
        _onexit((void (__cdecl*)())0xB1ABF0);
    }
}
