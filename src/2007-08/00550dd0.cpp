// from server: 15% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall RegOpenKeyExA(void*, const char*, unsigned long, unsigned long, void**);
extern "C" int __stdcall RegQueryValueExA(void*, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);
extern "C" int __stdcall RegCloseKey(void*);
extern "C" int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
extern "C" unsigned char* __cdecl _mbsstr(const unsigned char*, const unsigned char*);

extern "C" void __cdecl func_00630b60();
extern "C" void __cdecl func_00630d23(void*);
extern "C" void __cdecl func_0062fc62(void*);
extern "C" void* __cdecl func_0062fef6(int);
extern "C" void __cdecl func_00725750();
extern "C" void __cdecl func_00725770();
extern "C" void __cdecl func_00547600();
extern "C" void __cdecl func_0054c560();
extern "C" void __cdecl func_0054b860();
extern "C" int __cdecl func_0054afb0(void*, void*);
extern "C" void __cdecl func_00413010();
extern "C" void __cdecl func_004130f0();
extern "C" void __cdecl func_004135a0();
extern "C" int __cdecl func_00550ba0(void*);
extern "C" int __cdecl func_00550a70(void*);
extern "C" void __cdecl func_00401000(int);

extern void* g_8c1c58;
extern unsigned long g_8c1c5c;
extern char g_8c1c60;

struct S {
    char pad[0x1268];
    int f();
};

int S::f()
{
    func_00630b60();
    func_00725750();
    if ((g_8c1c5c & 1) == 0) {
        g_8c1c5c |= 1;
        g_8c1c58 = 0;
        func_00630d23((void*)0x779a90);
    }
    if (g_8c1c58 == 0) {
        void* hkey1 = 0;
        void* hkey2 = 0;
        unsigned long type = 0;
        unsigned long size = 0;
        unsigned char buf[4];
        if (RegOpenKeyExA((void*)0x80000001, (const char*)0x78ba80, 0, 0x20019, &hkey1) == 0) {
            size = 4;
            RegQueryValueExA(hkey1, (const char*)0x7a7c30, 0, &type, buf, &size);
        }
        if (RegOpenKeyExA((void*)0x80000002, (const char*)0x790720, 0, 0x20019, &hkey2) == 0) {
            if (hkey1 != 0) RegCloseKey(hkey1);
            hkey1 = hkey2;
            size = 4;
            RegQueryValueExA(hkey1, (const char*)0x7a7c30, 0, &type, buf, &size);
        }
        unsigned char* p = (unsigned char*)func_0062fef6(1);
        if (p != 0) {
            *p = (size == 1) ? 1 : 0;
        } else {
            p = 0;
        }
        void* old = g_8c1c58;
        g_8c1c58 = p;
        func_0062fc62(old);
        if (hkey1 != 0) RegCloseKey(hkey1);
    }
    if (*(char*)g_8c1c58 != 0) {
        func_00725770();
        return 1;
    }
    func_00725770();
    func_00547600();
    void* p = (void*)0x1278;
    (void)p;
    return 0;
}
