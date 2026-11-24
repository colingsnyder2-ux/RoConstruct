// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: returns address of an unknown global data object (type unknown)
extern "C" char g_00940d7c;

extern "C" void* fn_004d7a70(void)
{
    return &g_00940d7c;
}
