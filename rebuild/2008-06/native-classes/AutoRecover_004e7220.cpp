// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: boost::function-style functor manager for an 8-byte small functor.
// Op 0 = clone, 1 = no-op (trivial destroy), 3 = get type, other = check type.
// Original typeinfo lives at 0x941918; the real functor type is unknown.
struct Functor8 {
    void* a;
    void* b;
};

extern "C" void fn_004e7220(const Functor8* in, void* out, int op)
{
    switch (op) {
    case 3:
        *(const std::type_info**)out = &typeid(Functor8);
        return;
    case 0:
        if (out)
            *(Functor8*)out = *in;
        return;
    case 1:
        return;
    default: {
        const std::type_info*& req = *(const std::type_info**)out;
        req = (*req == typeid(Functor8)) ? (const std::type_info*)in : 0;
        return;
    }
    }
}
