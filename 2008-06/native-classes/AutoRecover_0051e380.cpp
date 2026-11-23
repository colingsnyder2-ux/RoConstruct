// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: target is a bare tail-jump thunk to 0x0051b6b0; signature unknown, cdecl passthrough.
extern "C" void fn_0051b6b0();

extern "C" void fn_0051e380()
{
    fn_0051b6b0();
}
