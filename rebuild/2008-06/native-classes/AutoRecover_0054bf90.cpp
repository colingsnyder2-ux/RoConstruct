// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object has an int field at +4; unknown class, so a plain struct stands in.
struct Obj54bf90 {
    int unk0;
    int field4;
};

extern "C" int __fastcall fn_0054d430(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0054d660(void* self, int unusedEdx);

extern "C" void __fastcall fn_0054bf90(Obj54bf90* self, int unusedEdx)
{
    fn_0054d430(self, 0, self->field4 + 1, 0);
    fn_0054d660(self, 0);
}
