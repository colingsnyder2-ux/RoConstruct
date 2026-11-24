// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a sort_heap-style loop over 8-byte elements, calling a
// pop_heap-like helper. The callee is a __thiscall member helper that gets
// ecx = the value's high dword, which is still live in ecx at the call site,
// plus 5 stack arguments, so the declaration is trimmed to 5 args.
struct Elem8 {
    unsigned int lo;
    unsigned int hi;
};

extern "C" void fn_0067c780(HeapElem* first, int hole, int len, int v0, int v1);

// INFERRED: argument order is (first, last), cdecl.
extern "C" void fn_0067d1a0(Elem8* first, Elem8* last)
{
    int n = (int)(last - first);
    while (n > 1) {
        --last;
        Elem8 v = *last;
        *last = *first;
        n = (int)(last - first);
        fn_0067c780(v.hi, 0, first, 0, n, v.lo, v.hi);
    }
}
