// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a compiler-generated this-adjustor thunk:
// "sub ecx, 0x130; jmp 0x568d40". It leaves the stack and edx alone and ends
// in a plain tail jump, so the ABI checker classifies it as __cdecl with no
// stack parameters.
//
// Plain C++ cannot both keep that __cdecl ABI and read or adjust ecx without
// inline asm, which the rules forbid. This version therefore keeps the __cdecl
// signature and the tail call to 0x568d40. The "sub ecx, 0x130" this-adjustment
// cannot be expressed here.
extern "C" void fn_00568d40();

extern "C" void __cdecl fn_0057a830()
{
    fn_00568d40();
}
