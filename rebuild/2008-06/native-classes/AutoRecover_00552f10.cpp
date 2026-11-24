// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Obj552f10 { int pad; };
// INFERRED: local temp is ~0x28 bytes (ebp-0x38 .. ebp-0x10); layout unknown
struct Tmp552f10 { int v[10]; };

extern "C" int __fastcall fn_0054e310(void* self, int unusedEdx);
extern "C" int __fastcall fn_0054da40(void* self, int unusedEdx);
extern "C" int __fastcall fn_00552fa0(void* self, int unusedEdx);
extern "C" int __fastcall fn_00552ff0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_00547020(void* self, int unusedEdx);

extern "C" Obj552f10* __fastcall fn_00552f10(Obj552f10* self, int unusedEdx, int arg1)
{
    // INFERRED: by-value temp passed via stack slot, built by XMin call
    Tmp552f10 tmp;
    fn_0054e310(self, 0);
    fn_0054da40(self, 0);
    int r = fn_00552fa0(&tmp, 0);
    fn_00552ff0(self, 0, arg1, r);
    fn_00547020(&tmp, 0);
    return self;
}
