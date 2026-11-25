// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callee is a true __thiscall member (no edx setup in the original); a member decl
// avoids the fastcall dummy-edx zeroing. Mangled name aliased to the shared fn_ symbol.
struct Chatted_Event { int run(int a1, int a2, int a3); };
#pragma comment(linker, "/alternatename:?run@Chatted_Event@@QAEHHHH@Z=_fn_00492890")

extern "C" void fn_007fb770(void);
extern Chatted_Event g_0096fca0_obj;
extern "C" int __cdecl atexit(void (__cdecl *)(void));

// INFERRED: static initializer registering the "Chatted" event (message, recipient), then atexit destructor
extern "C" void fn_007f12c0(void)
{
    g_0096fca0_obj.run((int)"Chatted", (int)"message", (int)"recipient");
    atexit(fn_007fb770);
}
