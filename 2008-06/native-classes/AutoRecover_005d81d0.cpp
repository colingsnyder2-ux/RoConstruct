// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int fn_006a0920(int a1, int a2);
extern "C" char g_0083d31c[];           // INFERRED: GetSet vtable data symbol at 0x83d31c

// INFERRED: GetSet layout from the stores (vtable, +8 +0xc +0x10 +0x18 +0x1c +0x20).
struct Local_005d81d0Obj {
    void* vtbl;
    int pad4;
    int a, b, c;
    int pad14;
    int d, e, f;
};

// INFERRED: stands in for std::auto_ptr<GetSet>, returned via a hidden sret pointer.
struct Local_005d81d0Ptr {
    Local_005d81d0Obj* p;
};

// INFERRED: the code never reads ecx, so the "__thiscall" ABI guess is wrong. It reads
// 7 stack dwords (sret ptr + 6 values) and returns with ret 0, which is plain cdecl.
extern "C" Local_005d81d0Ptr* fn_005d81d0(Local_005d81d0Ptr* self,
    int a, int b, int c, int d, int e, int f)
{
    Local_005d81d0Obj* o = (Local_005d81d0Obj*)fn_006a0920(0x28, 0);
    if (o) {
        o->vtbl = g_0083d31c;
        o->a = a;
        o->b = b;
        o->c = c;
        o->d = d;
        o->e = e;
        o->f = f;
    }
    self->p = o;
    return self;
}
