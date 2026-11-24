// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: returns arg + 8 (cdecl, pointer-offset accessor); argument type unknown.
extern "C" char* fn_00541da0(char* self)
{
    return self + 8;
}
