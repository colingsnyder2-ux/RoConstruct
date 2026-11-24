// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_0054d390(void* self, int unusedEdx, int a1, int a2);

// INFERRED: constructor-like wrapper (returns this) that forwards two zero args to fn_0054d390
extern "C" void* __fastcall fn_0054bec0(void* self, int unusedEdx)
{
    fn_0054d390(self, 0, 0, 0);
    return self;
}
