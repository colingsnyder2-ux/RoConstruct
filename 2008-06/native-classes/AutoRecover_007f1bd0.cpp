// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00823244[];   // INFERRED: unnamed global at 0x00823244 in the original
extern "C" char g_00823258[];   // INFERRED: unnamed global at 0x00823258 in the original
extern "C" char g_00823260[];   // INFERRED: unnamed global at 0x00823260 in the original
extern "C" int __fastcall fn_004a0020(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __cdecl atexit(void (__cdecl *)(void));
extern "C" void fn_007fbb70(void);

// INFERRED: global object at 0x970c48 is a static signal/event object constructed with 3 args
extern char g_00970c48[];

extern "C" void fn_007f1bd0(void)
{
    // INFERRED: original thiscall leaves edx unset; uninitialized dummy avoids the xor
    int unusedEdx;
    fn_004a0020(g_00970c48, unusedEdx, ((int)&g_00823244), ((int)&g_00823258), ((int)&g_00823260));
    atexit(fn_007fbb70);
}
