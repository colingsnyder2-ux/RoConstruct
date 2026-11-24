// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x69fbd0 is a linker import thunk (jmp [IAT]) for dinput8!DirectInput8Create.
// Wrapper forwards the stdcall arguments; MSVC cannot emit a bare jmp thunk from C++.
extern "C" __declspec(dllimport) long __stdcall DirectInput8Create(
    void* hinst, unsigned long version, const void* riid, void** out, void* outer);

extern "C" long __stdcall fn_0069fbd0(
    void* hinst, unsigned long version, const void* riid, void** out, void* outer)
{
    return DirectInput8Create(hinst, version, riid, out, outer);
}
