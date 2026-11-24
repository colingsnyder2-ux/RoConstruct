// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were shown, so the boost::function and boost::any::holder
// layout is reproduced with file-local types.
// INFERRED: whether this compiles to the exact bytes is unverified.
#include <stddef.h>

namespace {

union function_buffer {
    void* obj_ptr;
    double align_dummy; // INFERRED: forces 8-byte alignment, so the buffer sits at +8 inside function_base
    char data[12];
};

struct vtable_base {
    // manager(in_buffer, out_buffer, op) : op 0 = clone_functor_tag
    void (*manager)(const function_buffer& in, function_buffer& out, int op);
};

struct function_base {
    vtable_base* vtable;
    function_buffer functor;

    function_base() : vtable(0) {}
    __forceinline function_base(const function_base& f) : vtable(0) {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, 0);
        }
    }
    ~function_base() {
        if (vtable) {
            vtable->manager(functor, functor, 2); // INFERRED: destroy_functor_tag
            vtable = 0;
        }
    }
};

struct placeholder {
    virtual ~placeholder() {}
};

struct holder : placeholder {
    function_base held;
    // INFERRED: the original function IS the holder constructor, so the constructor
    // is run directly on 'self' through an explicit constructor call (MSVC extension),
    // with no placement-new null check or placement-delete unwind state.
    __forceinline explicit holder(const function_base& value) : held(value) {}
};

} // namespace

extern "C" holder* __fastcall fn_0048dfb0(holder* self, int unusedEdx, const function_base* value)
{
    self->holder::holder(*value);
    return self;
}
