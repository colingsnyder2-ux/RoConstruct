// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The object pointer is passed as a cdecl argument.
extern "C" int __fastcall fn_0040e990(void* self);

extern "C" int __fastcall fn_0040ee70(void* self)
{
    return fn_0040e990(static_cast<char*>(self) + 8);
}
