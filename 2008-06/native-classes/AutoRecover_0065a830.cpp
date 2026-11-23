// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::copy_backward-style helper over 8-byte elements; returns new dest begin.
struct Elem8 { int a; int b; };

extern "C" Elem8* fn_0065a830(Elem8* first, Elem8* last, Elem8* destEnd)
{
    Elem8* result = destEnd - (last - first);
    while (first != last) {
        --last;
        --destEnd;
        *destEnd = *last;
    }
    return result;
}
