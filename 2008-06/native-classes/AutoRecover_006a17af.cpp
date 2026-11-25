// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: CRT atexit wrapper around _onexit (fn_006a170a); the disassembly pushes a single argument.
extern "C" void* fn_006a170a(void* a1);

extern "C" int __cdecl atexit(void (__cdecl *func)(void))
{
    return (fn_006a170a((void*)func) == 0) ? -1 : 0;
}
