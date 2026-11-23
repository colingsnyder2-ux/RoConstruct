// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: boost::function-style functor manager for a small (8-byte)
// trivially copyable functor stored in the function buffer.
// INFERRED: type_info of the functor lives at 0x00941700.
extern "C" const std::type_info fn_data_00941700;

union FunctionBufferLike {
    struct { unsigned int a; unsigned int b; } words;
    const std::type_info* type;
    void* obj_ptr;
};

extern "C" void fn_004e7100(const FunctionBufferLike* in, FunctionBufferLike* out, int op)
{
    switch (op) {
    case 3: // get type
        out->type = &fn_data_00941700;
        return;
    case 0: // clone
        if (out) {
            out->words.a = in->words.a;
            out->words.b = in->words.b;
        }
        return;
    case 1: // destroy (trivial)
        return;
    default: // check type tag
        if (*out->type == fn_data_00941700)
            out->obj_ptr = (void*)in;
        else
            out->obj_ptr = 0;
        return;
    }
}
