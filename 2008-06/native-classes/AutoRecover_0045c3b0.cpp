// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: boost::function-style functor manager for a small functor stored in-place (8 bytes).
// INFERRED: the type_info at 0x00932958 is declared as an extern C symbol so the address resolves at link time.
extern "C" const std::type_info g_typeinfo_00932958;

struct FunctionBuffer {
    union {
        const std::type_info* type;
        void* obj_ptr;
        unsigned int words[2];
    };
};

extern "C" void fn_0045c3b0(const FunctionBuffer* in, FunctionBuffer* out, int op)
{
    if (op == 3) {
        out->type = &g_typeinfo_00932958;
        return;
    }
    if (op == 0) {
        if (out) {
            out->words[0] = in->words[0];
            out->words[1] = in->words[1];
        }
        return;
    }
    if (op == 1)
        return;

    // check-type / other op
    const std::type_info* t = out->type;
    out->obj_ptr = (*t == g_typeinfo_00932958) ? (void*)in : 0;
}
