// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: small boost::function-style functor manager for an 8-byte trivially
// copyable functor stored in the function buffer. The real functor type is unknown,
// so a placeholder type stands in for the type_info at 0x9412d8.
struct fn_004db760_Functor {
    int a;
    int b;
};

struct fn_004db760_Buffer {
    union {
        const std::type_info* type;
        void* obj_ptr;
        int words[2];
    };
};

extern "C" void fn_004db760(const fn_004db760_Buffer* in, fn_004db760_Buffer* out, int op)
{
    if (op == 3) {
        // get_functor_type_tag
        out->type = &typeid(fn_004db760_Functor);
        return;
    }
    if (op == 0) {
        // clone
        if (out) {
            out->words[0] = in->words[0];
            out->words[1] = in->words[1];
        }
        return;
    }
    if (op == 1) {
        // destroy: trivial
        return;
    }
    // check_functor_type
    if (*out->type == typeid(fn_004db760_Functor))
        out->obj_ptr = (void*)in;
    else
        out->obj_ptr = 0;
}
