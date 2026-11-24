// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: layout from the disassembly: a tag/vtable dword at +0, payload of two dwords at +8.
struct PairVal {
    int a;
    int b;
};

struct Fn004db9e0Obj {
    const void* tag;    // +0 (vtable-like pointer / state)
    int pad;            // +4
    PairVal data;       // +8
};

// INFERRED: unknown global whose address is stored in the tag (originally immediate 0x826df0).
extern "C" char g_00826df0[];

// INFERRED: callee is StringConverter<CoordinateFrame>::convertToValue; cdecl, one stack arg.
extern "C" char fn_0060a2f0(PairVal* arg);

extern "C" Fn004db9e0Obj* __fastcall fn_004db9e0(Fn004db9e0Obj* self, int unusedEdx, int a, int b, int c)
{
    PairVal local;
    local.a = a;
    local.b = b;
    self->tag = 0;
    if (!fn_0060a2f0(&local)) {
        new (&self->data) PairVal(local);
        self->tag = g_00826df0;
        return self;
    }
    self->tag = 0;
    return self;
}
