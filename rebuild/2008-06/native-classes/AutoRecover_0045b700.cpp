// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

namespace RBX { class Instance; }

// INFERRED: fn_006a0920 is operator new(size); the disassembly pushes one argument,
// so it is declared with a single size parameter.
extern "C" void* fn_006a0920(unsigned int size);

namespace {

// INFERRED: a boost-style sp_counted_impl_p<Instance, Creatable<Instance>::Deleter>
// (vtable, use_count, weak_count, px, empty deleter slot = 0x14 bytes).
struct CountedImpl {
    virtual ~CountedImpl() {}
    virtual void dispose() {}
    virtual void destroy() {}
    int use_count;
    int weak_count;
    RBX::Instance* px;
    int deleterPad;

    explicit CountedImpl(RBX::Instance* p) : use_count(1), weak_count(1), px(p) {}
};

// INFERRED: the object at ECX is a shared_ptr-like holder whose first member is the
// count pointer.
struct SharedHolder {
    CountedImpl* pn;
};

}

extern "C" SharedHolder* __fastcall fn_0045b700(SharedHolder* self, int unusedEdx,
                                                RBX::Instance* p, int unusedArg2)
{
    self->pn = 0;
    CountedImpl* impl = new (fn_006a0920(0x14)) CountedImpl(p);
    self->pn = impl;
    return self;
}
