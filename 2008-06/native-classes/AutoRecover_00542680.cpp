// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct Obj542680;
extern "C" int __fastcall fn_005429e0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00544320(void* self, int unusedEdx, int a1);
// INFERRED: unwind state 0 after the first call means the base part is destroyed on exception.
// Real base dtor is unknown, so the unwind funclet will not match exactly.
extern "C" void __fastcall fn_unwind_542680(void* self);

struct BaseGuard542680 {
    void* p;
    ~BaseGuard542680() { fn_unwind_542680(p); }
};

extern "C" Obj542680* __fastcall fn_00542680(Obj542680* self, int unusedEdx, int a1, int a2)
{
    fn_005429e0(self, 0, a1);
    BaseGuard542680 g = { self };
    fn_00544320((char*)self + 0xc, 0, a2);
    g.p = 0;
    return self;
}
