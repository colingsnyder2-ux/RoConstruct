// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: the code is a boost::function-style copy. A vtable pointer sits at +0
// and its manager(in, out, op) is called with op 0 (clone) on the functor buffer at +8.
struct FnVTable {
    void (__cdecl *manager)(const void* in, void* out, int op);
};

struct FnBase {
    const FnVTable* vtable;
    int pad;
    char buffer[16];

    FnBase() : vtable(0) {}
    ~FnBase() {}  // INFERRED: nontrivial destructor, which explains the SEH frame in the original
    FnBase(const FnBase& o) : vtable(0)
    {
        if (o.vtable) {
            vtable = o.vtable;
            o.vtable->manager(&o.buffer[0], &buffer[0], 0);
        }
    }
};

// INFERRED: class with a vptr, one unknown field at +4, and the function holder at +8.
struct Fn42b010Obj {
    int unknown4;
    FnBase fn;

    explicit Fn42b010Obj(const FnBase* f) : fn(*f) {}
    virtual ~Fn42b010Obj() {}
};

extern "C" Fn42b010Obj* __fastcall fn_0042b010(Fn42b010Obj* self, int unusedEdx, const FnBase* f)
{
    return new (self) Fn42b010Obj(f);
}
