// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00944328[];   // INFERRED: unnamed global at 0x00944328 in the original
// INFERRED: the disassembly pushes four stack args and the caller pops them (add esp, 0x10), so the helper is plain cdecl here.
extern "C" void __cdecl fn_0055cfa0(int a1, int a2, int a3, int a4);

// INFERRED: signature (a, b, c), cdecl
extern "C" void __cdecl fn_0055d670(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_0055cfa0(a, b, c, *(int*)&zero);
        return;
    }
    // INFERRED: ((int)&g_00944328) is an address in the original, written as a plain immediate.
    *(int*)b = ((int)&g_00944328);
}
