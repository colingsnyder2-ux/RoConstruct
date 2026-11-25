// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: arg6 is a by-value ownership-transfer object (copy steals the
// pointer). The SEH frame and the zeroing of the incoming arg slot suggest it.
struct MoveArg {
    int p;
    MoveArg(const MoveArg& o) : p(o.p) { const_cast<MoveArg&>(o).p = 0; }
    ~MoveArg() {}
};

// INFERRED: 8-byte by-value argument to the base ctor ({0, stolen arg6}).
struct BaseArg {
    int a;
    int b;
    BaseArg(MoveArg& s) : a(0), b(s.p) { s.p = 0; }
    ~BaseArg() {}
};

// INFERRED: 8-byte by-value argument to classDescriptor (arg1, arg2) with a
// non-trivial destructor, which accounts for the second EH state.
struct PairArg {
    int a;
    int b;
    PairArg(int x, int y) : a(x), b(y) {}
    ~PairArg() {}
};

// INFERRED: the property descriptor is a plain object here. Its vptr is at +0
// and the owned getter/setter functor pointer is at +0x18.
struct SkinBrickColorDescriptor {
    void* vptr;
    char  base[0x14];
    void* functor;   // +0x18
};

// INFERRED: the functor is a 0x18-byte object. +0 vptr, +4 owner, +8 arg3,
// +0x10 arg4, +0x14 arg5. +0xC is left uninitialized by the original.
struct FunctorObj {
    void* vptr;
    SkinBrickColorDescriptor* owner;
    int   a3;
    int   pad;
    int   a4;
    int   a5;
};

extern "C" char g_0083c520[]; // vtable of the descriptor
extern "C" char g_0083c494[]; // vtable of the functor

// INFERRED: throw(...) keeps these callees "may throw" under /EHsc so the
// SEH frame is emitted as in the original.
extern "C" int fn_006a0920(int a1) throw(...);
// INFERRED: classDescriptor static is stdcall (callee pops its two args).
extern "C" void* __stdcall fn_005d4cb0(PairArg a) throw(...);
// INFERRED: base TypedPropertyDescriptor ctor, thiscall, class descriptor plus a by-value arg.
extern "C" void* __fastcall fn_0048b180(void* self, int unusedEdx, void* classDesc, BaseArg arg) throw(...);

extern "C" SkinBrickColorDescriptor* __fastcall fn_005d4ec0(SkinBrickColorDescriptor* self, int unusedEdx,
                                                            int a1, int a2, int a3, int a4, int a5, MoveArg a6)
{
    fn_0048b180(self, 0, fn_005d4cb0(PairArg(a1, a2)), BaseArg(a6));
    self->vptr = g_0083c520;

    FunctorObj* f = (FunctorObj*)fn_006a0920(sizeof(FunctorObj));
    FunctorObj* n;
    if (f) {
        f->vptr = g_0083c494;
        f->owner = self;
        f->a3 = a3;
        f->a4 = a4;
        f->a5 = a5;
        n = f;
    } else {
        n = 0;
    }

    void* old = self->functor;
    if (n != old && old)
        operator delete(old);
    self->functor = n;
    return self;
}
