// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: this is a boost::function functor manager for an 8-byte functor stored in-place.
// The functor type's typeinfo is at 0x941a90 in the original.
struct Fn004e72e0Functor {
    int a;
    int b;
};

// INFERRED: op 0 = clone, 1 = destroy (nothing to do), 2 = check type, 3 = get type
extern "C" void fn_004e72e0(const void* in, void* out, int op)
{
    if (op == 3) {
        *(const std::type_info**)out = &typeid(Fn004e72e0Functor);
        return;
    }
    if (op == 0) {
        if (out) {
            const int* src = (const int*)in;
            int* dst = (int*)out;
            dst[0] = src[0];
            dst[1] = src[1];
        }
        return;
    }
    if (op == 1)
        return;

    const std::type_info* ti = *(const std::type_info**)out;
    *(const void**)out = (*ti == typeid(Fn004e72e0Functor)) ? in : 0;
}
