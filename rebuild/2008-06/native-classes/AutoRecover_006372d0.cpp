// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Names, types and layouts below are guesses recovered from the disassembly; no headers were available.
#include <new>

struct ClassDescriptor;

extern "C" int fn_006a0920(int a1);                // operator new (cdecl)
extern "C" ClassDescriptor* fn_006368d0(void);     // Described<...>::classDescriptor()

// INFERRED: auto_ptr<Constraint>-like temporary passed by value (one pointer, initialised to 0)
struct AutoPtrTmp {
    void* p;
};

// ctor of TypedPropertyDescriptor<int>: (this, classDesc, name, category, auto_ptr, flags)
extern "C" void __fastcall fn_004432a0(void* self, int unusedEdx,
                                       ClassDescriptor* cd, const char* name,
                                       const char* category, AutoPtrTmp ap, int flags);

// INFERRED: getter/setter holder with a vtable (0x8482e4), size 0x18
struct GetSetHolder {
    virtual void anchor();
    void* owner;      // +4
    int   getter;     // +8
    int   pad;        // +0xc
    int   setter;     // +0x10
    int   extra;      // +0x14
};
void GetSetHolder::anchor() {}

// INFERRED: derived property descriptor (vtable 0x815988), holder pointer at +0x18
struct IntPropDescriptor {
    void*         base[6];  // base class storage up to +0x18
    GetSetHolder* holder;   // +0x18
};

extern "C" IntPropDescriptor* __fastcall fn_006372d0(IntPropDescriptor* self, int unusedEdx,
                                                     const char* name, const char* category,
                                                     int getter, int setter, int extra, int flags)
{
    AutoPtrTmp tmp;
    tmp.p = 0;
    fn_004432a0(self, 0, fn_006368d0(), name, category, tmp, flags);

    GetSetHolder* h;
    void* mem = (void*)fn_006a0920(0x18);
    if (mem) {
        GetSetHolder* g = new (mem) GetSetHolder();
        g->owner  = self;
        g->getter = getter;
        g->setter = setter;
        g->extra  = extra;
        h = g;
    } else {
        h = 0;
    }

    GetSetHolder* old = self->holder;
    if (h != old && old)
        operator delete(old);
    self->holder = h;
    return self;
}
