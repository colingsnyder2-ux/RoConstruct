// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Tail-call thunk: jmp 0x45b2b0
// INFERRED: callee signature unknown; cdecl, no args touched by this thunk.
extern "C" void fn_0045b2b0();

extern "C" void fn_0045b820()
{
    fn_0045b2b0();
}
