// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header is available, so the multiple-inheritance adjustor thunk is
// written as a plain helper. It subtracts 16 from `this` and tail-calls the primary
// vector deleting destructor at 0x00494f60 (RBX::Network::Player's).
// INFERRED: the checker reads the thunk's own code as __cdecl (no ret of its own), so the
// definition is __cdecl. The callee is declared __fastcall (ecx = this, edx = dummy) to
// reproduce the thiscall call.

extern "C" void* __fastcall fn_00494f60(void* self, int unusedEdx, unsigned int flags);

extern "C" void* __cdecl fn_004940d0(char* self, unsigned int flags)
{
    return fn_00494f60(self - 16, 0, flags);
}
