// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the caller pushes four stack args and pops 0x10 afterwards, so the callee is plain cdecl.
extern "C" void __cdecl fn_005a0a30(int a1, int a2, int a3, int a4);

// INFERRED: unknown global at 0x94b840 (likely a vtable); its address is stored into *b.
extern "C" char g_0094b840[];

extern "C" void __cdecl fn_005a1260(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_005a0a30(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = (int)g_0094b840;
}
