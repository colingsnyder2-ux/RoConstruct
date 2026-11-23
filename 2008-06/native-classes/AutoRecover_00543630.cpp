// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: takes a pointer argument and returns it offset by 0x14 bytes (cdecl).
extern "C" char* fn_00543630(char* base)
{
    return base + 0x14;
}
