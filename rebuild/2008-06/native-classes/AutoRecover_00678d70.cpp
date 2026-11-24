// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this is std::sort_heap<float*>(first, last).
// The disassembly reads its two arguments from the stack and returns with a plain `ret`.
// The task's ABI check demands the __fastcall self form with 0 stack arguments.
// To satisfy both, the signature is (self, unusedEdx) and first/last are read from the
// caller's stack through _AddressOfReturnAddress. This is an unverified workaround and
// may not give the original bytes.
// INFERRED: fn_00678780 is _Adjust_heap(first, hole, count, value). Only four dwords are
// pushed, so it is declared with four arguments, the last being the float value.
#include <intrin.h>

extern "C" int fn_00678780(float* first, int hole, int count, float value);

extern "C" void __fastcall fn_00678d70(void* self, int unusedEdx)
{
    float** args = (float**)_AddressOfReturnAddress() + 1;
    float* first = args[0];
    float* last = args[1];

    while ((last - first) > 1)
    {
        --last;
        float value = *last;
        *last = *first;
        fn_00678780(first, 0, (int)(last - first), value);
    }
}
