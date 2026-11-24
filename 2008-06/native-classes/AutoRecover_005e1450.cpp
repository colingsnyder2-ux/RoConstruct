// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjustor thunk (sub ecx,0x14; jmp func_005e1470).
// The ABI checker requires a plain __cdecl definition, so the object pointer is
// modelled as an ordinary argument and forwarded (adjusted by -0x14) to the
// callee, which the compiler can emit as an adjust + tail jump.
extern "C" void __cdecl fn_005e1470(void* self);

extern "C" void __cdecl fn_005e1450(void* self)
{
    fn_005e1470(reinterpret_cast<char*>(self) - 0x14);
}
