// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: takes one int argument and returns it plus 0x15 (cdecl)
extern "C" int fn_00541d90(int value)
{
    return value + 0x15;
}
