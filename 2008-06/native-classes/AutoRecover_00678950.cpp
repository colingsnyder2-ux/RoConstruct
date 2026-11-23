// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

// INFERRED: this is the std::sort insertion sort for float with operator<.
// The copy_backward is expected to compile to the memmove_s call seen in the disassembly.
extern "C" void fn_00678950(float* first, float* last)
{
    if (first == last)
        return;
    for (float* next = first + 1; next != last; ++next)
    {
        float val = *next;
        if (val < *first)
        {
            std::copy_backward(first, next, next + 1);
            *first = val;
        }
        else
        {
            float* hole = next;
            float* prev = next - 1;
            while (val < *prev)
            {
                *hole = *prev;
                hole = prev;
                --prev;
            }
            *hole = val;
        }
    }
}
