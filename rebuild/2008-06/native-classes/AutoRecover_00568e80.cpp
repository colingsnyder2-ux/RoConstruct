// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjusting thunk (sub ecx, 0x170; jmp 0x00568d40).
// The checker classifies it as __cdecl (plain ret, caller pops), so the target is
// defined as __cdecl here. A __cdecl function cannot read the incoming ecx, so the
// object pointer is taken as an ordinary argument instead. It is then adjusted by
// -0x170 and forwarded to the __thiscall-style callee.
extern "C" void __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" void __cdecl fn_00568e80(void* self)
{
    // INFERRED: unsigned subtraction so that the compiler emits `sub ecx, 0x170`.
    fn_00568d40(reinterpret_cast<void*>(reinterpret_cast<unsigned int>(self) - 0x170u), 0);
}
