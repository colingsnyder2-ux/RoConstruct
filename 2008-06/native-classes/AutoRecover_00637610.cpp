// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: all type layouts below are reconstructed from the disassembly only.
#include <new>

struct ClassDescriptor;

// INFERRED: one-dword temporary with a destructor (it is registered for unwinding in the original).
struct PropAttr {
    int v;
    PropAttr() : v(0) {}
    ~PropAttr() {}
};

struct GetSetImpl {
    void* vtbl;     // +0x00
    void* owner;    // +0x04
    int   a;        // +0x08
    int   pad;      // +0x0c (not written by the original)
    int   b;        // +0x10
    int   c;        // +0x14
};

struct Vec3PropDesc {
    void*       vtbl;       // +0x00
    char        base[0x14]; // +0x04 .. +0x17, initialised by the base constructor
    GetSetImpl* impl;       // +0x18
};

// INFERRED: unknown globals (vtables) referenced by address in the original.
extern "C" char g_00845ce4[];   // vtable of the derived property descriptor
extern "C" char g_00848334[];   // vtable of the getter/setter impl

extern "C" ClassDescriptor* fn_00636dd0(void);
extern "C" Vec3PropDesc* __fastcall fn_0059a4b0(Vec3PropDesc* self, int unusedEdx,
                                                ClassDescriptor* cd, const char* name,
                                                const char* category, PropAttr attr, int arg6);
extern "C" int fn_006a0920(int a1);

extern "C" Vec3PropDesc* __fastcall fn_00637610(Vec3PropDesc* self, int unusedEdx,
                                                const char* name, const char* category,
                                                int getter, int setter, int arg5, int arg6)
{
    // INFERRED: argument roles (getter/setter/etc.) are guesses.
    fn_0059a4b0(self, 0, fn_00636dd0(), name, category, PropAttr(), arg6);
    self->vtbl = (void*)g_00845ce4;

    GetSetImpl* p = (GetSetImpl*)fn_006a0920(0x18);
    GetSetImpl* n;
    if (p) {
        p->vtbl  = (void*)g_00848334;
        p->owner = self;
        p->a     = getter;
        p->b     = setter;
        p->c     = arg5;
        n = p;
    } else {
        n = 0;
    }

    GetSetImpl* old = self->impl;
    if (n != old && old) {
        ::operator delete(old);
    }
    self->impl = n;
    return self;
}
