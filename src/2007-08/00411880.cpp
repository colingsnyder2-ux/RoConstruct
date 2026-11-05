// from server: 37% by colin
extern "C" {
    __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int, unsigned long, const char*, int, wchar_t*, int);
    __declspec(dllimport) int __stdcall lstrlenA(const char*);
    __declspec(dllimport) void __stdcall SysFreeString(void*);
    __declspec(dllimport) void* __stdcall SysAllocString(const wchar_t*);
    __declspec(dllimport) int __stdcall VariantClear(void*);
    __declspec(dllimport) void __stdcall free(void*);
}

struct C {
    unsigned short m0;
    char pad[6];
    int m8;
    int f(const char*);
};

extern "C" void* __stdcall sub_8BAB64();
extern "C" void __stdcall sub_77E9D8(void*);
extern "C" int __stdcall sub_77D2F4(const char*);
extern "C" int __stdcall sub_77D318(void*, int, const char*, int, void*, int);
extern "C" void* __stdcall sub_77E9F4(void*);
extern "C" void __stdcall sub_77E6C4(void*);
extern "C" int __stdcall sub_630C50(int, int, int, int);
extern "C" int __stdcall sub_630BB0(int);
extern "C" int __stdcall sub_630A1E();
extern "C" int __stdcall sub_402AC0(int);
extern "C" void* __stdcall sub_4035E0(void*, int);
extern "C" void __stdcall sub_401000(int);

int C::f(const char* s)
{
    void* p = sub_8BAB64();
    sub_77E9D8(this);
    m0 = 8;
    if (s != 0)
        return 0;
    int len = sub_77D2F4(s);
    int n = len + 1;
    int hi = (n < 0) ? -1 : 0;
    int r = sub_630C50(n, hi, 2, 0);
    int lo = r;
    int h2 = hi;
    int t = lo + (int)0x80000000;
    int c = h2 + (t < (int)0x80000000 ? 1 : 0);
    if (c != 0 || (unsigned)t > 0xFFFFFFFFu)
        return 0;
    void* buf;
    if (lo <= 0x400 && sub_402AC0(lo)) {
        buf = (void*)sub_630BB0(lo);
    } else {
        buf = sub_4035E0((char*)this + 4, lo);
    }
    if (buf == 0)
        return 0;
    *(unsigned short*)buf = 0;
    int ok = sub_77D318(buf, -1, s, -1, 0, 0);
    void* res = ok ? buf : 0;
    void* h = sub_77E9F4(res);
    m8 = (int)h;
    if (h == 0 && s != 0) {
        m0 = 10;
        m8 = (int)0x8007000E;
        sub_401000(0x8007000E);
    }
    return (int)this;
}
