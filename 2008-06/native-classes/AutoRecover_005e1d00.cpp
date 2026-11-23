// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk. It subtracts 0xc4 from ecx (this) and
// tail-jumps to func_005e1de0. The callee's real signature is unknown, so it is
// declared as a __thiscall helper (__fastcall with a dummy edx) with no stack args.
extern "C" int __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" int __fastcall fn_005e1d00(void* self, int unusedEdx)
{
    return fn_005e1de0(static_cast<char*>(self) - 0xc4, unusedEdx);
}
