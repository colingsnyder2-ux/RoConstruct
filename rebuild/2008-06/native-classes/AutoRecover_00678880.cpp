// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the median-of-9 step of std::sort (_Median) over 4-byte
// elements. fn_00678720 is the three-element median (_Med3).
// The disassembly pushes exactly 3 stack args per call and the caller pops
// them, so I declare fn_00678720 as plain cdecl with 3 args instead of the
// suggested __fastcall form. ecx is only incidentally live at those calls.
extern "C" void fn_00678720(int* a, int* b, int* c);

extern "C" void fn_00678880(int* first, int* mid, int* last)
{
    int n = (int)(last - first);
    if (n > 40)
    {
        int step = (n + 1) / 8;
        fn_00678720(first, first + step, first + step * 2);
        fn_00678720(mid - step, mid, mid + step);
        fn_00678720(last - step * 2, last - step, last);
        fn_00678720(first + step, mid, last - step);
    }
    else
    {
        fn_00678720(first, mid, last);
    }
}
