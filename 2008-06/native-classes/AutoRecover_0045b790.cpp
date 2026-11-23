// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: operator-new-like allocator (cdecl, takes a size); the listed 9-arg
// signature is reduced to the single pushed argument seen at the call site.
extern "C" void* fn_006a0920(int size);

namespace RBX {
    class Instance;
    template <class T> struct Creatable {
        struct Deleter {
            void operator()(Instance* p);
        };
    };
}

// INFERRED: boost-style shared_ptr control block (vtable, use_count, weak_count, px, deleter)
struct SpCountedImpl {
    virtual void dispose() {}
    virtual void destroy() {}
    int use_count;
    int weak_count;
    RBX::Instance* px;
    RBX::Creatable<RBX::Instance>::Deleter del; // left uninitialised (empty functor)

    explicit SpCountedImpl(RBX::Instance* p) : use_count(1), weak_count(1), px(p) {}
};

// INFERRED: shared_count-like holder: ctor(Instance* p, Deleter d)
struct SharedCountHolder {
    SpCountedImpl* pi;
};

extern "C" SharedCountHolder* __fastcall fn_0045b790(SharedCountHolder* self, int unusedEdx,
                                                      RBX::Instance* p,
                                                      RBX::Creatable<RBX::Instance>::Deleter d)
{
    self->pi = 0;
    try {
        void* mem = fn_006a0920(0x14);
        self->pi = new (mem) SpCountedImpl(p);
    } catch (...) {
        d(p);
        throw;
    }
    return self;
}
