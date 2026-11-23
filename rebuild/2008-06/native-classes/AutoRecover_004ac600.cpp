// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: target is a single `jmp 0x4ab470` thunk; the callee's calling convention and
// signature are unknown, so it is declared as a bare C-linkage function and tail-called.
extern "C" void fn_004ab470();

extern "C" void fn_004ac600()
{
    fn_004ab470();
}
