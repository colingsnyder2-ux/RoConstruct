// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0083a5d8[];   // INFERRED: unnamed global at 0x0083a5d8 in the original
extern "C" char g_0083a5e8[];   // INFERRED: unnamed global at 0x0083a5e8 in the original
extern "C" char g_0083a5f8[];   // INFERRED: unnamed global at 0x0083a5f8 in the original
extern "C" char g_0083a608[];   // INFERRED: unnamed global at 0x0083a608 in the original
extern "C" char g_0083a618[];   // INFERRED: unnamed global at 0x0083a618 in the original
extern "C" char g_0083a628[];   // INFERRED: unnamed global at 0x0083a628 in the original
extern "C" char g_0083a638[];   // INFERRED: unnamed global at 0x0083a638 in the original
extern "C" char g_0083a640[];   // INFERRED: unnamed global at 0x0083a640 in the original
extern "C" char g_0083a648[];   // INFERRED: unnamed global at 0x0083a648 in the original
extern "C" char g_0083a654[];   // INFERRED: unnamed global at 0x0083a654 in the original
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" int __fastcall fn_005107a0(void* self, int unusedEdx);
// INFERRED: base destructor (FactoryProduct<Script,...>::~FactoryProduct) called as thiscall
extern "C" void __fastcall fn_005cc120(void* self, int unusedEdx);

struct Local_005cdbf0_Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Local_005cdbf0_Shared {
    void* object;
    Local_005cdbf0_Control* volatile control;
    __forceinline ~Local_005cdbf0_Shared()
    {
        Local_005cdbf0_Control* p = control;
        if (p) {
            if (_InterlockedDecrement(&p->strong) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weak) == 0)
                    p->destroy();
            }
        }
    }
};

struct Local_005cdbf0_Member {
    char pad[0xac];
    __forceinline ~Local_005cdbf0_Member() { fn_005107a0(this, 0); }
};

struct Local_005cdbf0_Base {
    volatile unsigned long table0;
    char pad04[0x0c];
    volatile unsigned long table10;
    volatile unsigned long table14;
    char pad18[8];
    volatile unsigned long table20;
    volatile unsigned long table24;
    char pad28[0x1c];
    volatile unsigned long table44;
    char pad48[0x1c];
    volatile unsigned long table64;
    char pad68[0x1c];
    volatile unsigned long table84;
    char pad88[0x1c];
    volatile unsigned long tableA4;
    char padA8[0x1c];
    volatile unsigned long tableC4;
    char padC8[0x68];
    __forceinline ~Local_005cdbf0_Base() { fn_005cc120(this, 0); }
};

struct Local_005cdbf0 : Local_005cdbf0_Base {
    Local_005cdbf0_Member member;
    Local_005cdbf0_Shared shared;
    __forceinline ~Local_005cdbf0()
    {
        table0 = ((int)&g_0083a654);
        table10 = ((int)&g_0083a648);
        table14 = ((int)&g_0083a640);
        table20 = ((int)&g_0083a638);
        table24 = ((int)&g_0083a628);
        table44 = ((int)&g_0083a618);
        table64 = ((int)&g_0083a608);
        table84 = ((int)&g_0083a5f8);
        tableA4 = ((int)&g_0083a5e8);
        tableC4 = ((int)&g_0083a5d8);
    }
};

extern "C" void __fastcall fn_005cdbf0(Local_005cdbf0* self, int unusedEdx)
{
    self->~Local_005cdbf0();
}
