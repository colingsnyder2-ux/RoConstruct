// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a this-adjusting thunk ("sub ecx,0x14; jmp 0x568d40").
// The target ABI is required to be __cdecl, and ecx cannot be read from C++
// without inline asm, so the object pointer is taken as the (only) stack
// argument and forwarded, adjusted by -0x14, in ecx to the real implementation.
// INFERRED: callee is a __thiscall-style member (modelled as __fastcall with dummy edx);
// its return type and any further stack arguments are unknown, so int/none is used.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __cdecl fn_00568d30(void* self)
{
    return fn_00568d40((void*)((char*)self - 0x14), 0);
}
