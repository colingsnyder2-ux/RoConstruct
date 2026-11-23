// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a bare thunk (single jmp to 0x00455ea0). Its signature is
// unknown, so both functions are declared with no parameters and the call compiles to a tail jump.
extern "C" void fn_00455ea0();

extern "C" void fn_00456400()
{
    fn_00455ea0();
}
