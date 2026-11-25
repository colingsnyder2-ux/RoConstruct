// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: base ctor is CCmdTarget::CCmdTarget (0x7bbfaa); declared as fn_ extern to avoid MFC header dependency.
// Callees take only ecx (original never sets edx before them), so declare them with one fastcall arg.
extern "C" int __fastcall fn_007bbfaa(void* self);
extern "C" int __fastcall fn_00795700(void* self);

struct Fn00795760Obj {
    void* vtable;                 // 0x00
    char pad0[0x1C];              // 0x04..0x1F (CCmdTarget base)
    char sub[0x14];               // 0x20..0x33 (constructed by fn_00795700)
    int field34;                  // 0x34
    int field38;                  // 0x38
};

extern "C" Fn00795760Obj* __fastcall fn_00795760(Fn00795760Obj* self, int unusedEdx)
{
    fn_007bbfaa(self);
    self->vtable = (void*)0x86b7fc;
    fn_00795700(self->sub);
    self->field34 = 0;
    self->field38 = 0;
    return self;
}
