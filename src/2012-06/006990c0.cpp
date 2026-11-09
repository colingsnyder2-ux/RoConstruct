// from server: 9% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    char pad[0x1c];
    void* field_1c;
    String();
    String(const String&);
    ~String();
};

struct RefCounted {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    long ref1;
    long ref2;
};

extern "C" void __stdcall sub_4015a0();
extern "C" void __stdcall sub_695720();
extern "C" void __stdcall sub_72e9f0();
extern "C" void __stdcall sub_743cb0();
extern "C" void __stdcall sub_684200();
extern "C" void __stdcall sub_93f690();
extern "C" void __stdcall sub_698870();
extern "C" void __stdcall sub_699000();
extern "C" void __stdcall sub_4026a0();

extern "C" void __stdcall dword_b2263c();
extern "C" void __stdcall dword_b22644();

struct SoundServiceStatsItem {
    char pad0[0x8c];
    char field_8c[4];
    void func(int, int, int, int, int, int, int, int);
};

void SoundServiceStatsItem::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    char buf[0x38];
    void* p;
    int old;

    sub_699000();
    sub_4015a0();
    sub_695720();
    sub_72e9f0();
    dword_b2263c();
    sub_743cb0();
    dword_b22644();
    sub_698870();
    sub_684200();
    sub_93f690();
    sub_4026a0();

    p = *(void**)(buf + 0x10);
    if (p) {
        old = _InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1);
        if (old == 1) {
            (*(void(__thiscall**)(void*))p)(p);
            old = _InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1);
            if (old == 1) {
                (*(void(__thiscall**)(void*))(*(void**)p))(p);
            }
        }
    }
    dword_b2263c();
}
