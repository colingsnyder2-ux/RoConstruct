// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: this looks like a boost::function-style functor manager for a small
// 8-byte functor stored in-place in the function buffer.
// op 0 = clone, 1 = destroy (no-op), 3 = get_type, anything else = check_type.
struct FunctorBuf8 {
    int a;
    int b;
};

union FunctionBuffer {
    void* obj_ptr;
    const std::type_info* type;
    int data[2];
};

extern "C" void fn_004e71c0(const FunctionBuffer* in, FunctionBuffer* out, int op)
{
    if (op == 3) {
        out->type = &typeid(FunctorBuf8);
        return;
    }
    if (op == 0) {
        if (out) {
            out->data[0] = in->data[0];
            out->data[1] = in->data[1];
        }
        return;
    }
    if (op == 1)
        return;
    // check_type
    if (*out->type == typeid(FunctorBuf8))
        out->obj_ptr = const_cast<FunctionBuffer*>(in);
    else
        out->obj_ptr = 0;
}
