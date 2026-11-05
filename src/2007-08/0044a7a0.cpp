// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl __argc;
extern "C" char** __argv;

struct string {
    void* rep;
    string();
    ~string();
    string& operator+=(const char*);
    const char* c_str() const;
};

struct CRobloxApp {
    char pad0[0x24];
    char f24;
    char f25;
    char f26;
    char f27;
    char pad28[4];
    int f2c;
    int f30;
    int f34;
    CRobloxApp();
};

extern "C" void __stdcall sub_63087a();
extern "C" void __stdcall sub_630a1e();
extern "C" void* __cdecl sub_56c3b0(void**);
extern "C" void __cdecl sub_56c0a0(void*, int, void*);

extern void* g_77e958;
extern void* g_77e95c;
extern void* g_77e6a4;
extern void* g_77e6a8;
extern void* g_77e6ac;
extern void* g_77e660;
extern const char g_787034[];

CRobloxApp::CRobloxApp()
{
    sub_63087a();
    *(void**)this = (void*)0x7909c4;
    f24 = 0;
    f25 = 0;
    f26 = 0;
    f27 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    if (*(int*)g_77e958 > 0) {
        string s;
        int i = 0;
        while (i < *(int*)g_77e958) {
            if (i != 0)
                s += g_787034;
            s += *(const char**)(*(int*)g_77e95c + i * 4);
            i++;
        }
        void* p = sub_56c3b0((void**)&s);
        void* q = (void*)((char*)p - 4);
        sub_56c0a0(q, 1, (void*)s.c_str());
        if (p) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[1])(p);
                if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                    void** vt2 = *(void***)p;
                    ((void (__thiscall*)(void*))vt2[2])(p);
                }
            }
        }
    }
}
