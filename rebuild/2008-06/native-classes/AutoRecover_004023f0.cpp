// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: thiscall member (ecx=this) copying one dword from arg pointer; unknown owner class.
extern "C" void __stdcall fn_004023f0_impl(unsigned* self, const unsigned* src);

extern "C" unsigned __fastcall fn_004023f0(unsigned* self, int unusedEdx, const unsigned* src)
{
    *self = *src;
    return 0;
}
