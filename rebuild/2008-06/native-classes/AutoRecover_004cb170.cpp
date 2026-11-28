// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the callee is called with four pushed stack args and the caller pops (add esp,0x10),
// so it is declared __cdecl here even though it was listed as a thiscall-style helper.
extern "C" int __cdecl fn_004ca360(int a1, int a2, int a3, int a4);

// INFERRED: unknown global (likely a vtable or static table) whose address is stored into *b.
extern "C" char g_0093cd10[];

// INFERRED: the target name is unknown, so it uses the fn_<address> convention.
extern "C" void __cdecl fn_004cb170(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_004ca360(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = (int)g_0093cd10;
}
