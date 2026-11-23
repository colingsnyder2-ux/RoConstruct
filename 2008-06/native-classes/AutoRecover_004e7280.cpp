// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: this is a boost::function functor manager for an 8-byte functor stored in the buffer.
// Op codes: 0 = clone, 1 = destroy, 2 = check type, 3 = get type.
// 0x009419d8 is the type_info of the stored functor type.
extern "C" const std::type_info g_typeinfo_009419d8;

struct FunctionBuffer {
    union {
        struct {
            void* a;
            void* b;
        } words;
        const std::type_info* type;
        void* obj_ptr;
    };
};

extern "C" void fn_004e7280(const FunctionBuffer* in, FunctionBuffer* out, int op)
{
    if (op == 3) {
        out->type = &g_typeinfo_009419d8;
        return;
    }
    if (op == 0) {
        if (out) {
            out->words.a = in->words.a;
            out->words.b = in->words.b;
        }
        return;
    }
    if (op == 1)
        return;
    // check_functor_type
    if (*out->type == g_typeinfo_009419d8)
        out->obj_ptr = (void*)in;
    else
        out->obj_ptr = 0;
}
