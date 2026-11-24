// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: adjustor thunk (this -= 0x64, tail jump); callee 0x568d40 is __thiscall, return type and stack args unknown.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

extern "C" int __fastcall fn_00568d10(void* self, int unusedEdx)
{
    return fn_00568d40(static_cast<char*>(self) - 0x64, unusedEdx);
}
