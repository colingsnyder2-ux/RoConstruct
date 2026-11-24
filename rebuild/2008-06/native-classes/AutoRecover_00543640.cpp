// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target takes one pointer argument and returns the address
// of the member at offset 0xc. The real types are unknown, so it is typed
// as a byte pointer.
extern "C" char* fn_00543640(char* self)
{
    return self + 0xc;
}
