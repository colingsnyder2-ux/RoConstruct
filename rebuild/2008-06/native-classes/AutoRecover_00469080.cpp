// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unnamed getter returning dword member at +0x5c
extern "C" int __fastcall fn_00469080(char* self, int unusedEdx)
{
    return *(int*)(self + 0x5c);
}
