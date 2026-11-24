// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: 8-byte small functor payload, copied by value for op 0 (boost::function-style manager)
struct Functor { int a; int b; };

extern "C" void fn_004e7160(const Functor* in, void* out, int op)
{
    if (op == 3) {
        *(const std::type_info**)out = &typeid(Functor);
    } else if (op == 0) {
        if (out)
            *(Functor*)out = *in;
    } else if (op != 1) {
        const std::type_info** p = (const std::type_info**)out;
        *p = (*(const std::type_info*)*p == typeid(Functor)) ? (const std::type_info*)in : 0;
    }
}
