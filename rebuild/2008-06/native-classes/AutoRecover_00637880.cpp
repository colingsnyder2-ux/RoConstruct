// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so every type here is a local stand-in.
// Ptr is a one-dword by-value argument whose copy constructor takes ownership
// and zeroes the source (matches the zeroing of arg6 in the disassembly).
struct Ptr {
    void* p;
    Ptr() : p(0) {}
    Ptr(Ptr& o) : p(o.p) { o.p = 0; }
};

struct Accessor {      // the 0x18-byte heap object built in the middle of the function
    void* vtbl;
    void* owner;
    int   a;
    int   unused;
    int   b;
    int   c;
};

struct PropDesc {      // INFERRED: base TypedPropertyDescriptor<BrickColor> is 0x18 bytes
    void* vtbl;
    char  base[0x14];
    Accessor* accessor;
};

extern "C" int fn_006a0920(int a1);
extern "C" int fn_00637190();   // Described<Value<BrickColor,...>>::classDescriptor()
// TypedPropertyDescriptor<BrickColor>::TypedPropertyDescriptor(ClassDescriptor&, name, category, X, arg6)
extern "C" void __fastcall fn_0048b180(PropDesc* self, int unusedEdx, int classDesc, int name, int category, Ptr x, Ptr y);

extern "C" void operator_delete_stub();
extern char g_0083c520[];
extern char g_00848370[];

extern "C" PropDesc* __fastcall fn_00637880(PropDesc* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, Ptr a6)
{
    fn_0048b180(self, 0, fn_00637190(), a1, a2, Ptr(), a6);
    self->vtbl = (void*)g_0083c520;

    Accessor* acc = (Accessor*)fn_006a0920(0x18);
    if (acc) {
        acc->vtbl  = (void*)g_00848370;
        acc->owner = self;
        acc->a     = a3;
        acc->b     = a4;
        acc->c     = a5;
    }

    Accessor* old = self->accessor;
    if (acc != old && old)
        ::operator delete(old);
    self->accessor = acc;
    return self;
}
