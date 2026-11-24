// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object layout {void* px; void* pn; sub-object at +8}; arg is a pair of dwords.
struct Pair { int a; int b; };
struct Obj { int px; int pn; };

extern "C" int __fastcall fn_004d8700(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_0041ad40(void* self, int unusedEdx);
extern "C" int __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);

extern "C" Obj* __fastcall fn_004d9610(Obj* self, int unusedEdx, Pair* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004d8700((char*)self + 8, 0, arg->a, arg->b, 0);
    void* d = (void*)fn_006a0920(0x28);
    if (d)
        fn_0041ad40(d, 0);
    fn_0041b0f0(self, 0, d);
    fn_00595840(self, 0);
    return self;
}
