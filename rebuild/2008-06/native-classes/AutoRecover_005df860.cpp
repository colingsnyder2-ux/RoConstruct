// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjustor thunk (ecx -= 0xa4, then tail-jump).
// Both functions are treated as __thiscall members, so they are declared __fastcall with a dummy edx.
extern "C" void __fastcall fn_005e1470(void* self, int unusedEdx);

extern "C" void __fastcall fn_005df860(void* self, int unusedEdx)
{
    fn_005e1470(reinterpret_cast<char*>(self) - 0xa4, unusedEdx);
}
