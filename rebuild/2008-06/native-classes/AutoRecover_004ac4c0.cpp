// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: this is boost::shared_count(Instance* p, Deleter d) for
// Creatable<Instance>::Deleter; the control block is 0x14 bytes:
// vtable, use_count, weak_count, ptr, empty deleter.
namespace RBX { class Instance; }

struct DeleterT { };

extern "C" void* fn_006a0920(int size);
extern "C" void __fastcall fn_00405e30(DeleterT* self, int unusedEdx, RBX::Instance* p);

struct CountedImpl {
    int use;
    int weak;
    RBX::Instance* ptr;
    DeleterT del;
    virtual void dispose() {}
    virtual void destroy() {}
    virtual void* get_deleter() { return 0; }
    CountedImpl(RBX::Instance* p) : use(1), weak(1), ptr(p) {}
};

struct SharedCount {
    CountedImpl* pi;
};

extern "C" SharedCount* __fastcall fn_004ac4c0(SharedCount* self, int unusedEdx, RBX::Instance* p, DeleterT d)
{
    self->pi = 0;
    try {
        self->pi = new (fn_006a0920(0x14)) CountedImpl(p);
    } catch (...) {
        fn_00405e30(&d, 0, p);
        throw;
    }
    return self;
}
