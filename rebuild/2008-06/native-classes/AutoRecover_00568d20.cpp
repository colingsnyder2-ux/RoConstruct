// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this-adjusting thunk (sub ecx,0x10; jmp func_00568d40) to a
// __thiscall member. The required ABI is __cdecl, and C++ cannot read ecx in a
// __cdecl function, so the object pointer is taken as a stack argument instead.
// The adjusted pointer is forwarded in ecx via __fastcall with a dummy edx,
// which lets the compiler emit a tail jmp.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __cdecl fn_00568d20(void* self)
{
    return fn_00568d40(reinterpret_cast<char*>(self) - 0x10, 0);
}
