// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// The target is a bare import thunk: jmp dword ptr [IAT] -> fmodex!FMOD_Memory_GetStats.
// INFERRED: The import is declared with no parameters so that /O2 turns the forwarding
// call into a tail-call jmp through the IAT slot. Any real arguments are already on the
// stack when the thunk is entered, so they pass through untouched.
// INFERRED: The import is declared __cdecl, so the decorated name here is not the real
// stdcall "@8" form. Only the emitted bytes are matched.
extern "C" __declspec(dllimport) int FMOD_Memory_GetStats(void);

extern "C" int fn_0069fc5a(void)
{
    return FMOD_Memory_GetStats();
}
