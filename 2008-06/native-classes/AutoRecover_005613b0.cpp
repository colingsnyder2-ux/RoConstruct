// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00944430[];   // INFERRED: unnamed global at 0x00944430 in the original
// INFERRED: signature of boost-style functor manager (a, b, op); callee is manage(const void* const*, void**, int)
extern "C" void __cdecl fn_00560f00(int, int, int, int);

extern "C" void __cdecl fn_005613b0(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_00560f00(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = ((int)&g_00944430);
}
