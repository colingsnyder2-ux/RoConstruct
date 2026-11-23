// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from offsets only (+0xc input, +0x10 result)
struct Fn552ff0Obj {
    int pad0[3];
    int f0c;
    int f10;
};

extern "C" unsigned char __fastcall fn_00553160(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005531e0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_00542500(void* self, int unusedEdx);

extern "C" void __fastcall fn_00552ff0(Fn552ff0Obj* self, int unusedEdx, int a1, int a2)
{
    if (fn_00553160(self, 0, a1)) {
        try {
            self->f10 = fn_005531e0(self, 0, self->f0c, a1, a2);
        } catch (...) {
            fn_00542500(self, 0);
            throw;
        }
    }
}
