// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

// INFERRED: the original was built with fast floating point (fcom + test ah,5 / jp, value kept in a register).
#pragma float_control(precise, off)

// INFERRED: this is std::_Insertion_sort<float*>(first, last) from VS2008 <algorithm>,
// written out as a plain cdecl function. The memmove_s call is the inlined copy_backward.
extern "C" void fn_00678950(float* first, float* last)
{
    if (first != last) {
        for (float* next = first; ++next != last; ) {
            float* next1 = next;
            float val = *next;
            if (val < *first) {
                std::copy_backward(first, next, ++next1);
                *first = val;
            } else {
                for (float* first1 = next1; val < *--first1; next1 = first1)
                    *next1 = *first1;
                *next1 = val;
            }
        }
    }
}
