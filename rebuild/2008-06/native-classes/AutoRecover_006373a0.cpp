// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available. Everything below is reconstructed from the disassembly alone.
// INFERRED: argument types, the fn_00636a10 signature and the base constructor arguments are guesses.
// INFERRED: the original has an auto_ptr temporary with unwind (SEH) state, which is not reproduced.
#include <new>

struct PropImpl {
    void* vtbl;     // vtable g_008482f8
    void* owner;    // +4
    int   a;        // +8
    int   pad;      // +0xc (left uninitialised in the original)
    int   b;        // +0x10
    int   c;        // +0x14
};

struct BoolPropertyDescriptor {
    void*     vtbl;       // vtable g_0080bc18
    char      base[0x14]; // set up by the base constructor
    PropImpl* impl;       // +0x18
};

// INFERRED: unknown globals are the two vtables
extern "C" char g_0080bc18[];
extern "C" char g_008482f8[];

extern "C" int  __stdcall fn_00636a10(int name, int category);
extern "C" void __fastcall fn_0040a290(BoolPropertyDescriptor* self, int unusedEdx,
                                       int classDesc, int zero, int autoPtrArg);
extern "C" int  fn_006a0920(int a1);

extern "C" BoolPropertyDescriptor* __fastcall fn_006373a0(BoolPropertyDescriptor* self, int unusedEdx,
                                                           int arg1, int arg2, int arg3,
                                                           int arg4, int arg5, int arg6)
{
    int desc = fn_00636a10(arg1, arg2);
    fn_0040a290(self, 0, desc, 0, arg6);
    self->vtbl = g_0080bc18;

    PropImpl* p = (PropImpl*)fn_006a0920(0x18);
    if (p) {
        p->vtbl  = g_008482f8;
        p->owner = self;
        p->a     = arg1;
        p->b     = arg2;
        p->c     = arg3;
    }

    PropImpl* old = self->impl;
    if (p != old && old)
        ::operator delete(old);
    self->impl = p;
    return self;
}
