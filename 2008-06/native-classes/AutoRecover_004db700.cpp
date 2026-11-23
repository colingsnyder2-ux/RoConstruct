// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: boost::function-style functor manager; 8-byte small buffer, typeid at 0x941238 is the stored functor type.
struct FunctorBuf {
    const void* a;
    const void* b;
};

struct StoredFunctor {
    const void* a;
    const void* b;
};

extern "C" void fn_004db700(const FunctorBuf* in, FunctorBuf* out, int op)
{
    if (op == 3) {
        out->a = &typeid(StoredFunctor);
        return;
    }
    if (op == 0) {
        if (out) {
            out->a = in->a;
            out->b = in->b;
        }
        return;
    }
    if (op == 1)
        return;
    const std::type_info* t = (const std::type_info*)out->a;
    out->a = (*t == typeid(StoredFunctor)) ? (const void*)in : 0;
}
