// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: this is a boost::function small-object functor manager
// (clone / destroy / check-type). The 16-byte buffer is copied on clone.
struct fn_buffer_0055cfa0 {
    union {
        const std::type_info* type;
        void* obj_ptr;
    };
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
};

// INFERRED: stand-in for the functor type whose type_info lives at 0x944328.
struct fn_functor_0055cfa0 {
    int unused[4];
};

extern "C" void fn_0055cfa0(const fn_buffer_0055cfa0* in, fn_buffer_0055cfa0* out, int op)
{
    if (op == 0) {
        // clone
        if (out) {
            out->obj_ptr = in->obj_ptr;
            out->d1 = in->d1;
            out->d2 = in->d2;
            out->d3 = in->d3;
        }
        return;
    }
    if (op == 1) {
        // destroy: trivial functor, nothing to do
        return;
    }
    // check_functor_type
    if (*out->type == typeid(fn_functor_0055cfa0))
        out->obj_ptr = (void*)in;
    else
        out->obj_ptr = 0;
}
