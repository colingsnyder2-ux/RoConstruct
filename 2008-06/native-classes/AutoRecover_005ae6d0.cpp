// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, and a compiler-generated adjustor thunk
// cannot be written as ordinary C++. The original is "sub ecx,0x10 ; jmp 0x5aed20",
// which has no ret of its own, so the checker classes it as __cdecl.
// I model it as a free __cdecl function that subtracts 16 from `this` and forwards to
// the real vector deleting destructor at 0x005aed20 (thiscall, modelled as __fastcall).
// The extern "C" name fn_005ae6d0 stands in for ??_EScriptContext@RBX@@WBA@AEPAXI@Z.

extern "C" void* __fastcall fn_005aed20(void* self, int unusedEdx, unsigned int flags);

extern "C" void* fn_005ae6d0(void* self, unsigned int flags)
{
    return fn_005aed20(static_cast<char*>(self) - 16, 0, flags);
}
