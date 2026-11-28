// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the supplied __fastcall declaration for fn_005a0a90 does not fit the
// disassembly. The caller pushes 4 stack arguments and pops them itself
// (add esp, 0x10) without setting ecx, so this is declared as plain __cdecl.
extern "C" int __cdecl fn_005a0a90(int a1, int a2, int a3, int a4);

// INFERRED: the value stored at [b] is a vtable-like data address in the original exe.
extern "C" int g_0094b8c8[];

extern "C" void __cdecl fn_005a12a0(int a, int b, int c)
{
    if (c != 3)
    {
        // The low byte is zeroed and the upper bytes of the stack slot are
        // reused from c, then passed as the 4th argument.
        char zero = 0;
        fn_005a0a90(a, b, c, *(int*)&zero);
        return;
    }
    *(void**)b = (void*)g_0094b8c8;
}
