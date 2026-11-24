// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Array<Vector4> modeled as a 16-byte POD (data,num,alloc,flags at +0xc/+0xd); not compile-checked.
struct Arr16 {
    int a, b, c;
    unsigned char f0, f1, pad[2];
};

extern "C" unsigned char g_00970298; // INFERRED: unknown global byte
extern "C" void __stdcall fn_004974f0(SrcBase* obj, CountedRef ref, void* target);   // INFERRED: callback passed by address
extern "C" void __fastcall fn_00496ef0(Arr16* dst, int unusedEdx, const Arr16* src);
extern "C" int fn_00499430(Arr16* a1, void* a2, int a3, void* a4, int a5);
extern "C" int __fastcall fn_004984d0(void* self, int unusedEdx, Arr16 a, Arr16 b);
extern "C" void __fastcall fn_004995d0(void* self, int unusedEdx, Arr16* arg);

extern "C" void __fastcall fn_004995d0(void* self, int unusedEdx, Arr16* arg)
{
    Arr16 pair[2];
    arg->f0 = 1;
    fn_00496ef0(&pair[1], 0, arg);
    pair[1].f0 = arg->f0;
    pair[1].f1 = arg->f1;
    fn_00499430(&pair[0], (void*)fn_004974f0, 0, self, g_00970298);
    fn_004984d0(self, 0, pair[0], pair[1]);
}
