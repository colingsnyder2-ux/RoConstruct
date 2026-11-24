// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>
#include <new>

// INFERRED: this is a boost::function functor manager for an 8-byte functor
// stored in-place in the function buffer. typeid(F) is at 0x940c30 in the original.
struct Functor8 {
    int a;
    int b;
};

union FunctionBuffer {
    const std::type_info* type;
    const void* obj_ptr;
    Functor8 data;
};

extern "C" void fn_004d7810(const FunctionBuffer* in, FunctionBuffer* out, int op)
{
    if (op == 3) {
        // get_functor_type_tag
        out->type = &typeid(Functor8);
        return;
    }
    if (op == 0) {
        // clone_functor_tag
        new (&out->data) Functor8(in->data);
        return;
    }
    if (op == 1) {
        // INFERRED: trivially destructible functor, nothing to do
        return;
    }
    // check_functor_type_tag
    if (*out->type == typeid(Functor8))
        out->obj_ptr = in;
    else
        out->obj_ptr = 0;
}
