// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: 8-byte functor payload; the binary copies two dwords. The real type_info lives at 0x941b50.
struct Functor8 {
    int a;
    int b;
};

// INFERRED: boost::function-style manager. op 0 = clone, 1 = destroy, 2 = check type, 3 = get type.
extern "C" void fn_004e7340(Functor8* in, void* out, int op)
{
    if (op == 3) {
        *(const std::type_info**)out = &typeid(Functor8);
        return;
    }
    if (op == 0) {
        Functor8* dst = (Functor8*)out;
        if (dst) {
            dst->a = in->a;
            dst->b = in->b;
        }
        return;
    }
    if (op == 1)
        return;
    const std::type_info** slot = (const std::type_info**)out;
    *slot = (**slot == typeid(Functor8)) ? (const std::type_info*)in : 0;
}
