// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0084b2f0[];   // INFERRED: unnamed global at 0x0084b2f0 in the original
extern "C" char g_0084b2f8[];   // INFERRED: unnamed global at 0x0084b2f8 in the original
#include <new>

extern "C" int __cdecl fn_00583f40();
extern "C" int __cdecl fn_005fe7f0();
extern "C" void __cdecl fn_006a067a(void *);

// INFERRED: local types, real class names unknown
struct Local_0064e390_Owner
{
    void *p;
    ~Local_0064e390_Owner()
    {
        if (p)
            fn_006a067a(p);
    }
    void *release()
    {
        void *q = p;
        p = 0;
        return q;
    }
};

extern "C" Local_0064e390_Owner __cdecl fn_0064e220(int, int, int);

struct Local_0064e390_Base;
extern "C" void __fastcall fn_0056c650(Local_0064e390_Base *self, int unusedEdx, int, int, int, int, int);

struct Local_0064e390_Base
{
    unsigned long words[7];
    Local_0064e390_Base(int a, int b, int f)
    {
        int first = fn_00583f40();
        int second = fn_005fe7f0();
        fn_0056c650(this, 0, second, first, a, b, f);
    }
    ~Local_0064e390_Base();
};

struct Local_0064e390_S : Local_0064e390_Base
{
    void *value;
    // INFERRED: class-specific placement new without null check
    static void *operator new(unsigned int, void *p) { return p; }
    Local_0064e390_S(int a, int b, int c, int d, int e, int f)
        : Local_0064e390_Base(a, b, f)
    {
        words[0] = ((int)&g_0084b2f8);
        words[6] = ((int)&g_0084b2f0);
        value = fn_0064e220(c, d, e).release();
    }
};

extern "C" Local_0064e390_S * __fastcall fn_0064e390(Local_0064e390_S *self, int unusedEdx,
                                                     int a, int b, int c, int d, int e, int f)
{
    return new (self) Local_0064e390_S(a, b, c, d, e, f);
}
