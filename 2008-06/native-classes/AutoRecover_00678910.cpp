// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes only 4 stack args (add esp,0x10) and the caller pops them,
// so the callee is declared as a plain cdecl helper rather than the 7-arg __fastcall form.
extern "C" void __cdecl fn_00678780(float* first, int parent, int count, float value);

// INFERRED: this is a make_heap over a float range: sift down from count/2 - 1 to 0.
extern "C" void fn_00678910(float* first, float* last)
{
    int count = (int)(last - first);
    int parent = count / 2;
    while (parent > 0)
    {
        --parent;
        fn_00678780(first, parent, count, first[parent]);
    }
}
