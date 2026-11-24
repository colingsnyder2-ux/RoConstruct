// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callees are only known from disassembly names; types are guesses.
extern "C" int fn_005514a0(int a1);
extern "C" void __fastcall fn_004f0810(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004f0820(void* self, int unusedEdx, void* src);
extern "C" int __fastcall fn_0054bf70(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" void __fastcall fn_00489490(void* self, int unusedEdx, int a, int b, void* c, int d, int e);
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);

extern "C" void* __fastcall fn_00551400(void* self, int unusedEdx, void* arg1, void* arg2)
{
    fn_004f0810(self, 0);
    int size = fn_005514a0(8);
    char tmp[4];
    fn_004f0820(tmp, 0, arg2);
    int type = fn_0054bf70(arg1, 0);
    int qty = fn_00540e80(arg1, 0);
    fn_00489490(self, 0, qty, type, *(void**)tmp, size, 0);
    fn_00502a70(&arg2, 0);
    return self;
}
