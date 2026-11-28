// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: all types are guesses, since no class headers were available. This does not model the
// auto_ptr temporaries or EH states of the original; it only reproduces the visible calls, stores and control flow.

#include <new>

extern "C" int fn_006a0920(int a1);                // operator new
// INFERRED: callee pops its two args (no add esp after the call), so stdcall.
extern "C" void* __stdcall fn_00636b50(const char* a, const char* b);
extern "C" void __fastcall fn_00563c60(void* self, int unusedEdx, void* classDesc,
                                       int autoPtrNull, int arg6); // TypedPropertyDescriptor<int> ctor

// INFERRED: vtable symbols, addresses unknown in the relinked exe.
extern "C" char g_00848bb4[];   // property descriptor vtable
extern "C" char g_0084830c[];   // accessor vtable

struct AccessorObj {
    void* vtbl;     // +0x00
    void* owner;    // +0x04
    int   a;        // +0x08
    int   pad;      // +0x0c (not written by this function)
    int   b;        // +0x10
    int   c;        // +0x14
};

struct PropDesc {
    void*        vtbl;      // +0x00
    char         base[0x14];
    AccessorObj* accessor;  // +0x18
};

extern "C" PropDesc* __fastcall fn_00637470(PropDesc* self, int unusedEdx,
                                            const char* name, const char* category,
                                            int arg3, int arg4, int arg5, int arg6)
{
    fn_00563c60(self, 0, fn_00636b50(name, category), 0, arg6);
    self->vtbl = (void*)g_00848bb4;

    AccessorObj* p = (AccessorObj*)fn_006a0920(0x18);
    AccessorObj* n;
    if (p) {
        p->vtbl = (void*)g_0084830c;
        p->owner = self;
        p->a = arg3;
        p->b = arg4;
        p->c = arg5;
        n = p;
    } else {
        n = 0;
    }

    AccessorObj* old = self->accessor;
    if (n != old) {
        if (old)
            ::operator delete(old);
    }
    self->accessor = n;
    return self;
}
