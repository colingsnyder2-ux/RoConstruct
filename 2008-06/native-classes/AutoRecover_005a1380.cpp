// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes four stack args and the caller pops them
// (add esp,0x10), with no ecx setup, so the callee is declared cdecl here,
// as in the verified analog, rather than as the fastcall helper form.
extern "C" void __cdecl fn_005a0400(int a1, int a2, int a3, int a4);

// INFERRED: the value stored at 0x94ba80 is the address of an unknown global
// (probably a vtable), so it is declared as an extern symbol.
extern "C" char g_0094ba80[];

extern "C" void __cdecl fn_005a1380(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_005a0400(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = (int)g_0094ba80;
}
