// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: file-local mimic of boost::function<void(shared_ptr<Instance>)>
// (vtable pointer at +0, functor buffer at +8) and of boost::any::holder<>,
// because the vendor boost headers are not available here.
struct FnVTable {
    void (__cdecl *manager)(const void* in, void* out, int op);
};

union FnBuffer {
    double align;
    char data[8];
};

struct FnBase {
    FnVTable* vtable;
    FnBuffer functor;

    __forceinline FnBase(const FnBase& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(&f.functor, &functor, 0);
        }
    }
    ~FnBase()
    {
        if (vtable)
            vtable->manager(&functor, &functor, 2);
    }
};

struct AnyPlaceholder {
    virtual ~AnyPlaceholder() {}
};

struct AnyHolder : AnyPlaceholder {
    FnBase held;
    __forceinline AnyHolder(const FnBase& value) : held(value) {}

    // INFERRED: placement new without throw() so no null test is emitted.
    static __forceinline void* operator new(size_t, void* p) { return p; }
    static __forceinline void operator delete(void*, void*) {}
};

extern "C" AnyHolder* __fastcall fn_004b1dc0(AnyHolder* self, int unusedEdx, const FnBase* value)
{
    return new (self) AnyHolder(*value);
}
