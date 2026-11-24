// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjusting thunk. It subtracts 0x64 from ecx
// (the __thiscall `this`) and tail-jumps to the real function at 0x005e1470.
// The "cdecl" ABI hint is just the plain ret, not the actual calling convention.
extern "C" void __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" void __fastcall fn_005e1460(void* self, int unusedEdx)
{
    fn_005e1470(static_cast<char*>(self) - 0x64, unusedEdx);
}
