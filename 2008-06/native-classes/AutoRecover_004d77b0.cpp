// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: this looks like a boost::function functor manager for an 8-byte,
// trivially copyable functor stored in the function buffer.
// op 0 = clone, 1 = destroy (no-op), 2 = check type, 3 = get type.

// INFERRED: the type_info object at 0x00940b90 is referenced as an external symbol.
extern "C" const std::type_info ti_00940b90;

struct fn_buf_004d77b0 {
    union {
        struct {
            unsigned int a;
            unsigned int b;
        } data;
        const std::type_info* type;
        const void* obj_ptr;
    };
};

extern "C" void fn_004d77b0(const fn_buf_004d77b0* in, fn_buf_004d77b0* out, int op)
{
    if (op == 3) {
        out->type = &ti_00940b90;
        return;
    }
    if (op == 0) {
        if (out) {
            out->data.a = in->data.a;
            out->data.b = in->data.b;
        }
        return;
    }
    if (op == 1)
        return;
    // check type
    bool same = (*out->type == ti_00940b90);
    out->obj_ptr = same ? (const void*)in : (const void*)0;
}
