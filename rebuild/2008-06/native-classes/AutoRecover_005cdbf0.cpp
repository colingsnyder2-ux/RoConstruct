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
    void Destroy();   // INFERRED: thiscall helper corresponding to fn_005107a0
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
    int Destroy();   // INFERRED: thiscall helper corresponding to fn_005cc120
};

struct Local_005cdbf0 {
    Local_005cdbf0_Base base;
    Local_005cdbf0_Member member;
    Local_005cdbf0_Shared shared;
};

__forceinline void Local_005cdbf0_body(Local_005cdbf0* self)
{
    self->base.table0 = (unsigned long)&g_0083a654;
    self->base.table10 = (unsigned long)&g_0083a648;
    self->base.table14 = (unsigned long)&g_0083a640;
    self->base.table20 = (unsigned long)&g_0083a638;
    self->base.table24 = (unsigned long)&g_0083a628;
    self->base.table44 = (unsigned long)&g_0083a618;
    self->base.table64 = (unsigned long)&g_0083a608;
    self->base.table84 = (unsigned long)&g_0083a5f8;
    self->base.tableA4 = (unsigned long)&g_0083a5e8;
    self->base.tableC4 = (unsigned long)&g_0083a5d8;
    Local_005cdbf0_Control* p = self->shared.control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
    self->member.Destroy();
    volatile int sink = self->base.Destroy();
    (void)sink;
}

extern "C" void __fastcall fn_005cdbf0(Local_005cdbf0* self, int unusedEdx)
{
    Local_005cdbf0_body(self);
}
