// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the disassembly pushes four stack args and the caller cleans up
// (add esp,0x10) without loading ecx for the call, so fn_005a09d0 is declared
// __cdecl here rather than the __fastcall form suggested in the task.
extern "C" int __cdecl fn_005a09d0(int a1, int a2, int a3, int a4);

// INFERRED: unknown global at 0x94b7c8 (probably a vtable); the target stores its address.
extern "C" char g_0094b7c8[];

// INFERRED: this target's own name is unknown, so it uses the fn_<address> convention.
extern "C" void __cdecl fn_005a1220(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        fn_005a09d0(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = (int)g_0094b7c8;
}
