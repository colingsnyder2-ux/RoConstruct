// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: ecx/edx both used as pointers, so this is a __fastcall comparator over two float[3] (descending lexicographic order).
extern "C" int __fastcall fn_004dc360(const float* a, const float* b)
{
    if (a[0] > b[0]) return -1;
    if (a[0] < b[0]) return 1;
    if (a[1] > b[1]) return -1;
    if (a[1] < b[1]) return 1;
    if (a[2] > b[2]) return -1;
    if (a[2] < b[2]) return 1;
    return 0;
}
