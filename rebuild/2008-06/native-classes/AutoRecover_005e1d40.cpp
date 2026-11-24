// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a thiscall thunk that adjusts `this` by -0x44 (a
// secondary-base-to-primary-base adjustment) and tail-jumps to func_005e1de0.
// The callee's signature and return type are unknown; assumed no stack arguments.
extern "C" void __fastcall fn_005e1de0(void* self, int unusedEdx);

extern "C" void __fastcall fn_005e1d40(void* self, int unusedEdx)
{
    fn_005e1de0(static_cast<char*>(self) - 0x44, unusedEdx);
}
