// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: thiscall thunk adjusting ecx by +0x54 and tail-jumping to 0x006dd6b0.
extern "C" int __fastcall fn_006dd6b0(void* self);

extern "C" int __fastcall fn_006dba00(char* self)
{
    return fn_006dd6b0(self + 0x54);
}
