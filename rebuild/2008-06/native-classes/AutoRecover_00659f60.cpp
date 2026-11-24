// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: 8-byte POD element
struct Elem8 {
    int a;
    int b;
};

inline void* operator_new_place(size_t, void* p) { return p; }

extern "C" Elem8* fn_00659f60(Elem8* first, Elem8* last, Elem8* dest)
{
    if (first != last) {
        do {
            if (dest) {
                dest->a = first->a;
                dest->b = first->b;
            }
            ++first;
            ++dest;
        } while (first != last);
    }
    return dest;
}
