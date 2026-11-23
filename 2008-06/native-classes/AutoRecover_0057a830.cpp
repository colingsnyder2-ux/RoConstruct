// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 0x57a830 is a this-adjusting thunk (thiscall, ecx -= 0x130, tail jump). Real args and return type unknown.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_0057a830(void* self, int unusedEdx)
{
    return fn_00568d40(static_cast<char*>(self) - 0x130, unusedEdx);
}
