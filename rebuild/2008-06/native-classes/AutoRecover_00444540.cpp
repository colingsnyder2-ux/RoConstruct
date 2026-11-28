// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The target forwards an adjusted object pointer.
extern "C" void __fastcall fn_00443cf0(void* self);

extern "C" void __fastcall fn_00444540(void* self)
{
    fn_00443cf0(static_cast<char*>(self) + 4);
}
