// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were available, so every type below is a minimal local stand-in.
// The object layout comes from the disassembly offsets, and the callee prototypes are guessed.
#include <intrin.h>

struct PartInstance;

struct SpCountedBase {
    virtual void dispose() = 0;   // vtable slot +0
    virtual void destroy() = 0;   // vtable slot +4
    long use_count;               // +4 (after vptr)
    long weak_count;              // +8
};

struct SharedPtrRaw {
    void* px;
    SpCountedBase* pn;
};

struct ScopedConnRaw {
    void* vptr_or_pad;
    int a;
    int b;
    char c;
    char pad0[3];
    char d;
};

struct PartJoint {
    char pad0[0xd8];
    SharedPtrRaw part;           // 0xd8
    ScopedConnRaw conn1;         // 0xe0
    char pad1[0xf4 - 0xe0 - sizeof(ScopedConnRaw)];
    ScopedConnRaw conn2;         // 0xf4
};

// INFERRED: unknown globals (vtable, float constant, signal descs) declared as externs.
extern "C" char g_00826ef8;      // INFERRED: vtable of this class
extern "C" float g_0082d1c8;     // INFERRED: float constant passed to base ctor
extern "C" char g_00973c38;      // INFERRED: signal desc object #1
extern "C" char g_00973f48;      // INFERRED: signal desc object #2

// INFERRED: slot functors (member callbacks)
extern "C" void fn_004e83b0();
extern "C" void fn_004e6b90();

// INFERRED: shared_from<PartInstance>(PartInstance*) returns its sret pointer in eax.
extern "C" SharedPtrRaw* __cdecl fn_00618a40(SharedPtrRaw* out, PartInstance* p);
extern "C" int __fastcall fn_004eaae0(void* self, int unusedEdx, float a1, int a2, int a3);
extern "C" int __fastcall fn_004ea860(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ea900(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0042b680(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_004a3340(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_00595540(void* self, int unusedEdx, int other);   // scoped_connection::operator=
extern "C" void __fastcall fn_00595370(void* self, int unusedEdx);             // ~connection
extern "C" void __fastcall fn_0049f710(void* self, int unusedEdx);             // ~slot

static inline void releaseSp(SpCountedBase* pn)
{
    if (pn) {
        if (_InterlockedDecrement(&pn->use_count) == 0) {
            pn->dispose();
            if (_InterlockedDecrement(&pn->weak_count) == 0)
                pn->destroy();
        }
    }
}

extern "C" PartJoint* __fastcall fn_004eae10(PartJoint* self, int unusedEdx,
                                             int arg1, PartInstance* part, int arg3)
{
    SharedPtrRaw tmp;
    fn_00618a40(&tmp, part);
    fn_004eaae0(self, 0, g_0082d1c8, (int)&tmp, arg3);
    releaseSp(tmp.pn);

    *(void**)self = (void*)&g_00826ef8;   // INFERRED: vtable pointer
    fn_00618a40(&self->part, part);

    self->conn1.a = 0;
    self->conn1.b = 0;
    self->conn1.c = 0;
    self->conn1.d = 0;
    self->conn2.a = 0;
    self->conn2.b = 0;
    self->conn2.c = 0;
    self->conn2.d = 0;

    int functor[2];
    int slot[5];
    int conn[2];
    char* inst = (char*)arg1;

    functor[0] = (int)&fn_004e83b0;
    functor[1] = (int)self;
    fn_004ea860(slot, 0, (int)functor);
    int r = fn_004a3340((void*)&g_00973c38, 0, (int)conn, inst ? (int)(inst + 0x14) : 0, (int)slot, 10);
    fn_00595540(&self->conn1, 0, r);
    fn_00595370(conn, 0);
    fn_0049f710(slot, 0);

    functor[0] = (int)&fn_004e6b90;
    functor[1] = (int)self;
    fn_004ea900(slot, 0, (int)functor);
    r = fn_0042b680((void*)&g_00973f48, 0, (int)conn, inst ? (int)(inst + 0x14) : 0, (int)slot, 10);
    fn_00595540(&self->conn2, 0, r);
    fn_00595370(conn, 0);
    fn_0049f710(slot, 0);

    return self;
}
