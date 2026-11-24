// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: self is a pointer-to-pointer holder; returns first dword of pointee or 0.
extern "C" int __fastcall fn_00402400(int** self, int unusedEdx)
{
    int* p = *self;
    if (p)
        return *p;
    return 0;
}
