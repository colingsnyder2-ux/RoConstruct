// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x00456400 is a single-jmp thunk to 0x00455ea0; the argument convention is unknown, so a void(void) tail call is used.
extern "C" void fn_00455ea0(void);

extern "C" void fn_00456400(void)
{
    fn_00455ea0();
}
