// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk. It subtracts 0x24 from ecx and tail-jumps to
// 0x5e1470. The target is declared __fastcall so that ecx (this) is visible, as the rules
// prescribe for __thiscall helpers. The return type and the extra arguments are unknown,
// so they are guessed.
extern "C" int __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" int __fastcall fn_005df840(void* self, int unusedEdx)
{
    return fn_005e1470(static_cast<char*>(self) - 0x24, unusedEdx);
}
