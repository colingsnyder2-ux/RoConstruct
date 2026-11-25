// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout, argument roles and the by-value owning-pointer types are guesses.
// The class is a TypedPropertyDescriptor<float>-derived property with an owned accessor at +0x18.
// The original has an SEH/EH frame: arg6 is a by-value owning pointer that is nulled when it is
// moved into an 8-byte by-value temporary, which is then handed to the base constructor.

extern "C" int fn_006a0920(int a1);

// INFERRED: Described<Rocket>::classDescriptor is callee-cleaned and takes two stack dwords.
extern "C" int __stdcall fn_00631060(const char* a, const char* b);

// INFERRED: unknown globals are vtables
extern "C" char g_00824134[];   // derived property descriptor vtable
extern "C" char g_008472d8[];   // accessor vtable

// INFERRED: auto_ptr-like owner (move on copy)
struct OwnedPtr
{
    int* p;
    OwnedPtr(OwnedPtr& o) : p(o.p) { o.p = 0; }
    ~OwnedPtr() { delete p; }
};

// INFERRED: 8-byte by-value temporary {0, moved pointer}
struct OwnedTemp
{
    void* zero;
    OwnedPtr ap;
    OwnedTemp(OwnedPtr& a) : zero(0), ap(a) {}
};

struct RocketPropertyDescriptor
{
    void* vtbl;          // +0x00
    char  base[0x14];    // +0x04 .. 0x17
    void* accessor;      // +0x18
};

struct RocketAccessor
{
    void* vtbl;   // +0x00
    void* owner;  // +0x04
    int   f8;     // +0x08
    int   fc;     // +0x0c (left uninitialised)
    int   f10;    // +0x10
    int   f14;    // +0x14
};

extern "C" int __fastcall fn_00445610(void* self, int unusedEdx, int desc, OwnedTemp t);

extern "C" RocketPropertyDescriptor* __fastcall fn_00631280(RocketPropertyDescriptor* self, int unusedEdx,
                                                            const char* arg1, const char* arg2, int arg3,
                                                            int arg4, int arg5, OwnedPtr arg6)
{
    fn_00445610(self, 0, fn_00631060(arg1, arg2), OwnedTemp(arg6));

    self->vtbl = g_00824134;

    RocketAccessor* acc = reinterpret_cast<RocketAccessor*>(fn_006a0920(0x18));
    RocketAccessor* neu;
    if (acc) {
        acc->vtbl  = g_008472d8;
        acc->owner = self;
        acc->f8    = arg3;
        acc->f10   = arg4;
        acc->f14   = arg5;
        neu = acc;
    } else {
        neu = 0;
    }

    RocketAccessor* old = reinterpret_cast<RocketAccessor*>(self->accessor);
    if (neu != old && old)
        ::operator delete(old);
    self->accessor = neu;
    return self;
}
