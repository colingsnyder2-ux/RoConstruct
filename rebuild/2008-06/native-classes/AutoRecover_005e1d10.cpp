// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: adjustor thunk, this -= 0x10 then tail-jump to the real method (thiscall, ecx=this).
extern "C" int __fastcall fn_005e1de0(void* self);

extern "C" int __fastcall fn_005e1d10(void* self)
{
    return fn_005e1de0((char*)self - 0x10);
}
