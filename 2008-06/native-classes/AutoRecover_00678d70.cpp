// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the code reads both arguments from the stack (first at esp+4, last at esp+8)
// and returns with a plain ret, so it is cdecl, not a thiscall member. This is
// std::sort_heap over a float range, with the pop_heap step inlined.
// INFERRED: the callee is declared with 4 arguments instead of the suggested 6, because
// the call site pushes four dwords (add esp, 0x10). It is probably the
// adjust-heap helper: (first, holeIndex, len, value).
extern "C" int fn_00678780(float* first, int holeIndex, int len, float value);

extern "C" void fn_00678d70(float* first, float* last)
{
    while ((last - first) > 1)
    {
        --last;
        float value = *last;
        *last = *first;
        fn_00678780(first, 0, (int)(last - first), value);
    }
}
