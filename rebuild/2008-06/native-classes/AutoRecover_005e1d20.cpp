// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk: it subtracts 0x14 from ecx (this) and tail-jumps to 0x5e1de0.
// The checker requires a __cdecl definition. A __cdecl function cannot read ecx directly,
// so the adjusted pointer is modelled as a first parameter and forwarded as ecx to the thiscall callee.
// INFERRED: the return type and any further stack arguments are unknown.
extern "C" int __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" int __cdecl fn_005e1d20(char* self)
{
    return fn_005e1de0(self - 0x14, 0);
}
