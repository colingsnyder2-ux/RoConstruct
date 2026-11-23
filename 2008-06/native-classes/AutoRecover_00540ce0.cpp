// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: iterator = 2 dwords (checked iterator), result of fn_00541ed0 is a 16-byte iterator range
struct FnRange { int f0, f1, l0, l1; };

extern "C" FnRange* __fastcall fn_00541ed0(void* self, int unusedEdx, FnRange* out, int arg);
extern "C" void fn_00545ed0(int f0, int f1, int l0, int l1, int* n);
extern "C" int __fastcall fn_00541e20(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);

extern "C" int __fastcall fn_00540ce0(void* self, int unusedEdx, int arg)
{
    FnRange r;
    int buf[2];
    int n;
    fn_00541ed0(self, 0, &r, arg);
    n = 0;
    fn_00545ed0(r.f0, r.f1, r.l0, r.l1, &n);
    fn_00541e20(self, 0, (int)buf, r.f0, r.f1, r.l0, r.l1);
    return n;
}
